#include <mutex>
#include <thread>
#include <iostream>
#include <functional>

using namespace std;

void printNumber(int n) {
    std::cout << n;
}

class ZeroEvenOdd {
private:
    int n;
    mutex z, e, o;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->e.lock();
        this->o.lock();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; i += 1) {
            z.lock();
            printNumber(0);
            i % 2 == 0 ? o.unlock() : e.unlock();
        }
        z.unlock();
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            e.lock();
            printNumber(i);
            z.unlock();
        }
        e.unlock();
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            o.lock();
            printNumber(i);
            z.unlock();
        }
        o.unlock();
    }
};


int main(int argc, char** argv) {
    ZeroEvenOdd sol {5};
    std::thread zeros(&ZeroEvenOdd::zero, &sol, printNumber);
    std::thread odds(&ZeroEvenOdd::odd, &sol, printNumber);
    std::thread evens(&ZeroEvenOdd::even, &sol, printNumber);
    zeros.join();
    odds.join();
    evens.join();
    cout << endl;
}