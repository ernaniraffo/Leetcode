#include <functional>
#include <thread>

using namespace std;

class FizzBuzz {
private:
    int n;
    int i;

    bool divisible(int x, int y) {
        return x % y == 0;
    }

public:
    FizzBuzz(int n) {
        this->n = n;
        i = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (i <= n) {
            if (divisible(i, 3) && !divisible(i, 5)) {
                printFizz();
                i += 1;
            }
            this_thread::yield();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (i <= n) {
            if (!divisible(i, 3) && divisible(i, 5)) {
                printBuzz();
                i += 1;
            }
            this_thread::yield();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        while (i <= n) {
            if (divisible(i, 3) && divisible(i, 5)) {
                printFizzBuzz();
                i += 1;
            }
            this_thread::yield();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (i <= n) {
            if (!divisible(i, 3) && !divisible(i, 5)) {
                printNumber(i);
                i += 1;
            }
            this_thread::yield();
        }
    }
};
