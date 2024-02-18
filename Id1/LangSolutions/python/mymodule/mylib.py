"""The library of functions for the callenge 1 of Project Euler"""

def summation(up_bound :int, multiple: int) -> int:
    """Calculate the sum of all multiples of 'multiple' less than 'up_bound'.
    Args:
        up_bound (int): The upper bound for the multiples.
        multiple (int): The number whose multiples are to be summed.

    Returns:
        int: The sum of all multiples of 'multiple' less than 'up_bound'.
    
    Examples:
        >>> summation(5000, 5)
        2497500
        >>> summation(123, 17)
        399
    
    """
    return multiple * (up_bound//multiple) * (up_bound//multiple+1) // 2

def gcd(number1: int, number2: int) -> int:
    """Find the greatest common divisor of two numbers.
    Args:
        number1 (int): The first number.
        number2 (int): The second number.
    
    Returns:
        The greatest common divisor of 'num1' and 'num2'.
    
    Examples:
        >>> gcd(19, 31)
        1
        >>> gcd(442, 72)
        2
    
    """
    while number2 != 0:
        number1, number2 = number2, number1 % number2
    return number1

def lcm(number1: int, number2: int) -> int:
    """Find the least common multiple of two numbers.
    Args:
        number1 (int): The first number.
        number2 (int): The second number.
    
    Returns:
        The least common multiple of 'a' and 'b'.
    
    Examples:
        >>> lcm(33, 19)
        627
        >>> lcm(31,13)
        403
    
    """
    return int(number1*number2 / gcd(number1, number2))

def solve(up_bound: int, multiple1: int, multiple2: int) -> int:
    """ Find the sum of the multiples of 'multiple1' and 'multiple2' below 'up_bound'
    Args:
        up_bound (int): The upper limit for considering multiples.
        multiple1 (int): The first multiple to consider.
        multiple2 (int): The second multiple to consider.
    
    Returns:
        The sum of the multiples of 'multiple1' and 'multiple2' that are less than 'up_bound'.
    
    Examples:
        >>> solve(1500, 3, 7)
        481609
        >>> solve(33, 7, 17)
        87
    
    """
    up_bound -= 1
    if multiple1 % multiple2 == 0 or multiple2 % multiple1 == 0:
        multiple = min(multiple1, multiple2)
        return summation(up_bound, multiple)
    sum1 = summation(up_bound, multiple1)
    sum2 = summation(up_bound, multiple2)
    sum1_2 = summation(up_bound, lcm(multiple1, multiple2))
    result = sum1 + sum2 - sum1_2
    return result
