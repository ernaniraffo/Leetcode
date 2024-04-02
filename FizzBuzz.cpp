#include <functional>
#include <thread>
#include <vector>
#include <iostream>

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

void printFizz() {
    std::cout << "fizz" << std::endl;
}

void printBuzz() {
    std::cout << "buzz" << std::endl;
}

void printFizzBuzz() {
    std::cout << "fizzbuzz" << std::endl; 
}

void printNumber(int x) {
    std::cout << x << std::endl;
}

int main(int argc, char** argv) {
    int n = 15;
    if (argc > 1) {
        n = stoi(argv[1], nullptr);
    }
    FizzBuzz f(n);

    thread a(&FizzBuzz::buzz, &f, function<void()>(printBuzz));
    thread b(&FizzBuzz::fizz, &f,  function<void()>(printFizz));
    thread c(&FizzBuzz::fizzbuzz, &f, function<void()>(printFizzBuzz));
    thread d(&FizzBuzz::number, &f, function<void(int)>(printNumber));

    a.join();
    b.join();
    c.join();
    d.join();

    return 0;
}
