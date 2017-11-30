#include <thread>

void do_something()
{
    /* something */
}

void do_something_else()
{
    /* something else */
}

class background_task
{
    public:
        void operator()() const {
            do_something;
            do_something_else();
        }
};

int main()
{
    background_task f;
    std::thread my_thread_1(f);
    std::thread my_thread_2(background_task()); // No threads running
    std::thread my_thread_3((background_task()));
    std::thread my_thread_4{background_task()};
    std::thread my_thread_5([]{
                do_something();
                do_something_else();
                });

    return 0;
}

