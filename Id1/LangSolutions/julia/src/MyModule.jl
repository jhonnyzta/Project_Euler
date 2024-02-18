module MyModule

    export solve

    """
    summation(up_bound::Int64,num::Int64)->Int64
    
    Return the sum of all multiples of 'num' less than 'up_bound'.

    # Arguments
    
    * `up_bound::Int64`: The upper bound for the multiples.
    * `num::Int64`: The number whose multiples are to be summed.
    # Returns
    
    `Int64`: The sum of all multiples of 'num' less than 'up_bound'.
    
    # Examples

    ```jldoctest
    julia> summation(10,3)
    18
    ```
    """
    function summation(up_bound::Int64, num::Int64)::Int64
        div(num * div(up_bound, num) * (div(up_bound, num)+1), 2)
    end

    """
    gcd(num1::Int64, num2::Int64)::Int64
    
    Find the greatest common divisor of two numbers.

    #Arguments
        * `number1::Int64`: The first number.
        * `number2::Int64`: The second number.
    #Returns
        The greatest common divisor of 'num1' and 'num2'.
    #Examples
    
    ```jldoctest
    julia> gcd(19,31)
    1
    ```

    """
    function gcd(num1::Int64, num2::Int64)::Int64
        
        while num2!=0
            num1, num2 = num2, num1 % num2
        end
        num1
    end

    """
    lcm(num1::Int64, num2::Int64)::Int64

    Find the least common multiple of two numbers.
    #Arguments
        `number1::Int64`: The first number.
        `number2::Int64`: The second number.

    #Returns
        Return the least common multiple of two numbers.
    #Examples
    ```jldoctest
    julia> lcm(31,13)
    403
    ```
    """
    function lcm(num1::Int64, num2::Int64)::Int64
        div(num1 * num2, gcd(num1, num2))
    end

    """
    solve(up_bound::Int64, num1::Int64, num2::Int64)::Int64
    
    Find the sum of the multiples of 'multiple1' and 'multiple2' below 'up_bound'
    # Arguments
        `up_bound::Int64`: The upper limit for considering multiples.
        `multiple1::Int64`: The first multiple to consider.
        `multiple2::Int64`: The second multiple to consider.

    # Returns
        Return the sum of the multiples of 'multiple1' and 'multiple2' below 'up_bound'.
    #Examples
    ```jldoctest
    julia> solve(33, 7, 17)
    87
    ```
    """
    function solve(up_bound::Int64, num1::Int64, num2::Int64)::Int64
        #First, it is verified that the multiples entered are not multiples of each other.
        up_bound -= 1
        if num1 % num2 == 0 || num2 % num1 == 0
            summation(up_bound, min(num1, num2))
        else
            sum1 = summation(up_bound, num1)
            sum2 = summation(up_bound, num2)
            sum1_2 = summation(up_bound, lcm(num1, num2))
            sum1 + sum2 - sum1_2
        end
    end
end
