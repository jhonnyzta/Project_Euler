"""
The main code is practically the same for all the challenges of the Euler Project,
the only changes are those referring to the variables and value of the challenge
to be solved.
For information on the logic see 'mylib.py' in the module folder
"""
from timeit import timeit
from mymodule.mylib import solve

if __name__ == '__main__':
    # Values of challenge 1 of the Euler project
    UPPER_BOUND = 1000
    MULTIPLE1 = 3
    MULTIPLE2 = 5
    # Warm-up execution, prepares the system to perform iterative execution
    result = solve(UPPER_BOUND, MULTIPLE1, MULTIPLE2)
    # Measuring the average time gives a better result than measuring a single execution.
    time = timeit(lambda: solve(UPPER_BOUND, MULTIPLE1, MULTIPLE2),
                                 number=100)
    average_time = time/100
    print(f"\tResult: {result}")
    print(f"\tTime elapsed: {average_time:.3e}s")

# I was 'person' 985971th who solved this problem.
