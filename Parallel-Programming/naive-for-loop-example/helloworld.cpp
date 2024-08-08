#include <omp.h>
#include <chrono>
#include <iostream>

long sumSerial(int n) {
    long sum = 0;

    for (int i=1; i<=n; i++) sum += i;

    return sum;
}

long sumParallel(int n) {
    long sum = 0;

    #pragma omp parallel for reduction(+ : sum) num_threads(6)
    for (int i=1; i<=n; i++) sum += i;

    return sum;
}

int main() {
    const int n = 1000000000;

    auto startTime = std::chrono::high_resolution_clock::now();
    long resSerial = sumSerial(n);
    auto endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> serialDuration = endTime - startTime;

    startTime = std::chrono::high_resolution_clock::now();
    long resParallel = sumParallel(n);
    endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> parallelDuration = endTime - startTime;

    std::cout << "Serial result: " << resSerial << std::endl;
    std::cout << "Parallel result: " << resParallel << std::endl; 
    std::cout << "Serial duration: " << serialDuration.count() << " seconds" << std::endl; 
    std::cout << "Parallel duration: " << parallelDuration.count() << " seconds" << std::endl; 
    std::cout << "Speedup: " << serialDuration.count() / parallelDuration.count() << std::endl; 

    return 0;
}