class Foo {
private:
    int count;
    mutex m;
    condition_variable cv;
public:
    Foo() {
        count = 0;
    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> lock(m);
        printFirst();
        count++;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [this] { return count == 1; });
        printSecond();
        count++;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [this] { return count == 2; });
        printThird();
    }
};
