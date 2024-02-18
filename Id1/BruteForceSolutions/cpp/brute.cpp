#include <iostream>
#include <chrono>
#include <iomanip>
#include <cmath>

int brute() {
    int accumulator = 0;
    for (int i = 1; i < 1000; ++i){
        if (i % 3 == 0 || i % 5 == 0) {
            accumulator += i;
        }
    }
    return accumulator;
}

int main() {
    const int num_iterations = 100;
    double tiempo = 0;
    int result = brute();

    
    for (int i = 0; i < num_iterations; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        brute();
        auto stop = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> duration = stop - start;
        tiempo += duration.count();
    }

    int average_time = static_cast<int>(std::round((tiempo / num_iterations) * 1e6));
    std::cout << result << std::endl;
    std::cout << average_time << std::endl;
}