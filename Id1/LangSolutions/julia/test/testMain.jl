include("../src/MyModule.jl")

#For better understanding, first look at 'MyModule.jl' and 'Main.jl'
function main(args)
    if length(args) == 0
        up_bound = 1000
        multiple1 = 3
        multiple2 = 5
    elseif length(args) == 3
        try
            up_bound = parse(Int64, args[1])
            multiple1 = parse(Int64, args[2])
            multiple2 = parse(Int64, args[3])
        catch
            println("Conversion error. The execution is stopped.")
            return
        end
        if up_bound<multiple1 || up_bound<multiple2 #Check that the 'up_bound' is greater than the multiples.
            println("Error: 'up_bound' must be greater than multiples.")
            return
        elseif up_bound<0 || multiple1<0 || multiple2<0
            println("Error: Error: Only positive integers are allowed")
            return            
        end
    else
        println("Error: Three integers numbers expected <up_bound> <multiple1> <multiple2>")        
        return
    end

    total_time = 0.0
    num_iterations = 100
    result = 0

    for _ in 1:num_iterations
        _, time_elap, _, _, _ = @timed result = MyModule.solve(up_bound, multiple1, multiple2)
        total_time += time_elap
    end

    average_time = trunc(Int, (total_time / num_iterations)*1e9) #Here it send the time in nanoseconds to work with the result with bash

    println(result)
    println(average_time) 
end

main(ARGS)