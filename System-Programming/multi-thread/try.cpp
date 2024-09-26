#include <iostream>
#include <thread>
#include <string>

void inf_loop(std::string s) {
    while (true) std::cout << s << std::endl;
}

int main() {
    std::thread t1(inf_loop, "dog");
    // std::thread t2(inf_loop, "pig");

    inf_loop("cat");

    return 0;
}