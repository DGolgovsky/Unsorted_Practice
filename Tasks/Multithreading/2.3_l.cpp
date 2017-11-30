#include <thread>

void do_something_in_current_thread();

class thread_guard
{
private:
    std::thread& t;
public:
    explicit thread_guard(std::thread& t_)
        : t(t_)
    { }
    ~thread_guard() {
        if (t.joinable()) {
            t.join();
        }
    }
    thread_guard(thread_guard const&) = delete;
    thread_guard& operator=(thread_guard const&) = delete;
};

struct func; // 2.1_l.cpp example

void f()
{
    int some_local_state = 0;
    std::thread t(func(some_local_state));
    thread_guard g(t);
    do_something_in_current_thread();
}

