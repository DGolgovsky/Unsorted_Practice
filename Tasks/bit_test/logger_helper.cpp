#include <array>
#include <streambuf>
#include <ostream>
#include <optional>
#include <pgtypes_timestamp.h>
#include <iostream>
#include <sstream>
#include <utility>
#include <string_view>
#include <type_traits>

struct stack_buffer {
    std::array<char, 1024> buffer;
    std::size_t it = 0;

    template<typename T>
    void Put(T &value) {
        if (std::is_pointer<T>::value) {
            for (auto &ch : value) {
                buffer.at(it++) = ch;
            }
        } else if (std::is_reference<T>::value) {
            for (auto &ch : value) {
                buffer.at(it++) = ch;
            }
        } else {
            //buffer.at(it++) = value;
        }
    }

    void PutException(char value) {}
};

class BufferStd final : public std::streambuf {
private:
    int_type overflow(int_type c) override;
    std::streamsize xsputn(const char_type *s, std::streamsize n) override;
    stack_buffer &impl_;

public:
    explicit BufferStd(stack_buffer &impl) : impl_{impl} {}
    ~BufferStd() override = default;
};

class logger {
public:
    logger() { oss << timestamp(); }
    ~logger() { std::cerr << oss.str(); }
    template<typename T>
    logger &operator<<(T &value);

private:
    stack_buffer buffer_{};
    struct init_stream {
        BufferStd sbuf;
        std::ostream ostr;
        explicit init_stream(stack_buffer &impl) : sbuf{impl}, ostr(&sbuf) {}
    };

    std::optional<init_stream> lazy_;
    std::ostringstream oss;
    std::ostream &stream() {
        if (!lazy_)
            lazy_.emplace(buffer_);
        return lazy_->ostr;
    }
};

template<typename T>
logger &logger::operator<<(T &value) {
    if constexpr (std::is_constructible<std::string_view, T>::value) {
        buffer_.Put(value);
    } else if constexpr (std::is_base_of<std::exception, T>::value) {
        buffer_.PutException(value);
    } else {
        stream() << value;
    }
    return *this;
}

int main() {
    logger lh{};
    lh << "Test log message" << "\n";
}