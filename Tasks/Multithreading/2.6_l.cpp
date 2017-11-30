#include <thread>

class scoped_thread
{
private:
    std::thread t;
public:
    explicit scoped_thread(std::thread t_)
        : t(std::move(t_))
    {
        if (!t.joinable())
            throw std::logic_error("No threads");
    }
    ~scoped_thread()
    {
        t.join();
    }
    scoped_thread(scoped_thread const&) = delete;
    scoped_thread& operator=(scoped_thread const&) = delete;
};

struct func; // from 2.1_l.cpp

void f()
{
    int some_local_state;
    scoped_thread t(std::thread(func(some_local_state)));
    do_something_in_current_thread();
}

