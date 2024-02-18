#include "mylib.h"
#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>
#include <cmath>

int main(int argc, char** argv) {
    //For better understanding, first look at 'main.cpp'
    long long up_bound ;
    long long multiple1;
    long long multiple2;
    if (argc == 4) {
        try{
            up_bound = std::stoll(argv[1]);
            multiple1 = std::stoll(argv[2]);
            multiple2 = std::stoll(argv[3]);
        } catch (const std::exception& e) {
            std::cout << "Conversion error. The execution is stopped. " << e.what() << std::endl;
            return 0;
        }
        if (up_bound<multiple1 || up_bound<multiple2){ //Check that the 'up_bound' is greater than the multiples.
            std::cout<<"Error: 'up_bound' must be greater than multiples."<<std::endl;
            return 0;
        } else if (up_bound<0 || multiple1<0 || multiple2<0){
            std::cout<<"Error: Error: Only positive integers are allowed"<<std::endl;
            return 0;
        }
    } else if (argc == 1){
        up_bound = 1000;
        multiple1 = 3;
        multiple2 = 5;
    } else {
        std::cout << "Error: " << argv[0] << " Error: Three integers numbers expected <up_bound> <multiple1> <multiple2>" << std::endl;
        return 0;
    }
    long long result = solve(up_bound, multiple1, multiple2);
    const int num_iterations = 100;
    std::vector<double> times;
    times.reserve(num_iterations);

    for (int i = 0; i < num_iterations; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        
        long long res = solve(up_bound, multiple1, multiple2);
        
        auto stop = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> duration = stop - start;
        times.push_back(duration.count());
    }

    double sum = 0;
    for (double time : times) {
        sum += time;
    }
    int average_time = static_cast<int>(std::round((sum / num_iterations) * 1e6)); //Here it send the time in nanoseconds to work with the result with bash
    std::cout<<result<<std::endl;
    std::cout<< std::scientific << std::setprecision(3);
    std::cout<< average_time <<std::endl;
    return 0;
}
