#ifndef PAIR
#define PAIR

#include <string>

template <typename T>
class Pair {
private:
    T first;
    int second;

public:
    Pair(T f, int s) : first(f) {
        second = s;
    };

    T funcA() {
        return first;
    };

    int funcB();

};

template <typename T>
int Pair<T>::funcB() {
    return second;
}

#endif
