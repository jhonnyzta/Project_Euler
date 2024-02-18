#!/usr/local/bin/julia
include("MyModule.jl")
using Printf

function main()
    #Values ​​of challenge 1 of the Euler project
    up_bound = 1000
    multiple1 = 3 
    multiple2 = 5
    #Variables for time measurement
    total_time = 0.0
    num_iterations = 100
    #Warm-up execution, prepares the system to perform iterative execution and better measure the execution time
    result = MyModule.solve(up_bound, multiple1, multiple2)
    #Measuring the average time gives a better result than measuring a single execution.
    for i in 1:num_iterations
        _, time_elap, _, _, _ = @timed MyModule.solve(up_bound, multiple1, multiple2)
        total_time += time_elap
    end

    average_time = total_time / num_iterations

    println("\tResult: ",result)
    println("\tTime elapsed: ", @sprintf("%.3e", average_time), "s")
end

main()