#include <iostream>

class Foo
{
public:
    explicit Foo(int data) {
        std::cerr << "Constructor called" << std::endl;
        this->m_data = data;
    }
    ~Foo() = default;

    // Assignment operator
    Foo& operator=(const Foo& rhs) {
        std::cerr << "&operator= called" << std::endl;
        m_data = rhs.m_data;
        return *this;
    }

    // Copy Constructor
    Foo(const Foo& rhs) {
        std::cerr << "Copy Constructor called" << std::endl;
        m_data = rhs.m_data;
    }

    // Copy Constructor
    Foo(const Foo&& rhs) {
        std::cerr << "Move Constructor called" << std::endl;
        m_data = rhs.m_data;
    }

    int get_data() const {
        return m_data;
    }

private:
    int m_data;
};

int main()
{
    Foo foo(2); // Foo(int data) called

    Foo foo2(42);
    foo = foo2; // Assignment Operator Called

    Foo foo3 = foo; // Copy Constructor called

    Foo foo4 = std::move(foo2);

    std::cout << foo.get_data() << std::endl; // 42
    std::cout << foo3.get_data() << std::endl; // 42
    std::cout << foo4.get_data() << std::endl; // 42

    return 0;
}

