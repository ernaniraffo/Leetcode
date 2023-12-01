#include <mutex>
#include <functional>

class FooBar {
private:
    int n;
    std::mutex foo_mutex, bar_mutex;

public:
    FooBar(int n) {
        this->n = n;
        bar_mutex.lock();
    }

    void foo(std::function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            foo_mutex.lock();
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            bar_mutex.unlock();
        }
    }

    void bar(std::function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            bar_mutex.lock();
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            foo_mutex.unlock();
        }
    }
};
