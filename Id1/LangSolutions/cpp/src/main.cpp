#include "mylib.h"
#include <iostream>
#include <chrono>
#include <vector>

/**
 * The main code is practically the same for all the challenges of the Euler Project, the only changes are those referring to the variables and value of the challenge to be solved.
 * \brief <b>Note: </b> For information on the logic see 'mylib.h' in include folder
*/
int main() {
    //Values of challenge 1 of the Euler project, For simplicity they are defined as 'int', but functions work with 'long long'
    int up_bound = 1000;
    int multiple1 = 3;
    int multiple2 = 5;

    //Variables for time measurement
    const int num_iterations = 100; 
    std::vector<double> times;
    times.reserve(num_iterations); //Preassigns the size to the times vector.

    long long result = solve(up_bound, multiple1, multiple2); //Warm-up execution, prepares the system to perform iterative execution and better measure the execution time

    //Measuring the average time gives a better result than measuring a single execution.
    for (int i = 0; i < num_iterations; ++i) {
        auto start = std::chrono::high_resolution_clock::now(); //Start of time measurement
        
        long long res = solve(1000, 3, 5);
        
        auto stop = std::chrono::high_resolution_clock::now(); //End of time measurement
        std::chrono::duration<double, std::milli> duration = stop - start;
        times.push_back(duration.count());
    }

    double sum = 0;
    for (double time : times) {
        sum += time;
    }
    double average_time = (sum / num_iterations)/1000; //Division by 1000 to convert to seconds.
    std::cout<<"\tResult: "<<result<<std::endl;
    std::cout << "\tAverage time: " << average_time << "s" << std::endl;
    return 0;
}

//Answer: 233168
//I was 'person' 985971th who solved this problem.

