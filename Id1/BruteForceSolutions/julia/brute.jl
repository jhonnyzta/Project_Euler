function brute()::Int
    accumulator::Int = 0
    for i in 1:999
        if i % 3 == 0 || i % 5 == 0
            accumulator += i
        end
    end
    accumulator
end

function main()
    total_time::Float64 = 0.0
    num_iterations = 100
    result::Int = 0

    for _ in 1:num_iterations
        _, time_elap, _, _, _ = @timed result = brute()
        total_time += time_elap
    end

    average_time::Int = trunc(Int, (total_time/num_iterations)*1e9)

    println(result)
    println(average_time)
end

main()
