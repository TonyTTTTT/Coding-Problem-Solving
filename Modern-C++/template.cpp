#include <iostream>
#include <list>

template<typename T, int N>
class A {
    T array[N];
public:
    int getSize() {
        return N;
    }

    std::string getType() {
        return typeid(T).name();
    }
};

int main() {
    std::list<int> l;
    int n = 5;
    int *array = new int[n]{0};
    A<int, 8> a;
    int res = a.getSize();

    std::string type = a.getType();

    return 0;
}