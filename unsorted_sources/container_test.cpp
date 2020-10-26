// g++ this.cpp -O2 -lrt
#include <iostream>
#include <queue>
#include <deque>
#include <set>
#include <ctime>
#include <cstdlib>
#include <unistd.h>

using namespace std;

template <typename T>
double run_test(T& pq, int size, int iterations)
{
    struct timespec start, end;

    for (int i = 0; i < size; ++i)
        pq.push(rand());

    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &start);
    for (int i = 0; i < iterations; ++i) {
        if (rand()%2)
            pq.pop();
        else
            pq.push(rand());
    }
    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &end);

    end.tv_sec -= start.tv_sec;
    end.tv_nsec -= start.tv_nsec;
    if (end.tv_nsec < 0) {
        --end.tv_sec;
        end.tv_nsec += 1000000000ULL;
    }

    return (end.tv_sec*1e3 + end.tv_nsec/1e6);
}

template <class T>
class multiset_pq : public multiset<T>
{
public:
    multiset_pq()
        : multiset<T>()
    { };
    void push(T elm) { this->insert(elm); }
    void pop() {
        if (!this->empty())
            this->erase(this->begin());
    }
    const T& top() {
        return *this->begin();
    }
};

int main(int, char**)
{
    const int size = 5000;
    const int iterations = 100000;

    priority_queue< int, vector<int> > pqv;
    priority_queue< int, deque<int> > pqd;
    multiset_pq<int> pqms;

    srand(time(0));

    std::cout << "pq-w-vector: "   << run_test(pqv,  size, iterations) << "ms" << std::endl;
    std::cout << "pq-w-deque: "    << run_test(pqd,  size, iterations) << "ms" << std::endl;
    std::cout << "pq-w-multiset: " << run_test(pqms, size, iterations) << "ms" << std::endl;

    return 0;
}
