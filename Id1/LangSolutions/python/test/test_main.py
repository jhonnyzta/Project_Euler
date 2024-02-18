"""Script used for testing and performance measurement via bash."""

import sys
import os
from timeit import timeit # Used to measure execution time
from argparse import ArgumentParser # Used for parsing command-line arguments

script_path = os.path.abspath(__file__)
project_dir = os.path.dirname(os.path.dirname(script_path))
sys.path.insert(0, project_dir)
# For better understanding, first look at 'main.py' and 'mylib.py' in 'module' folder
if __name__ == '__main__':
    from mymodule.mylib import solve
    # Set up command-line argument parsing
    parser = ArgumentParser(
        description = 'Solution to the first challenge of the Euler project.'
        )
    parser.add_argument(
        'upper_bound', type = int, nargs = '?',
        default = 1000,
        help = 'Upper bound of terms of the sum of multiples. (default: 1000)'
        )
    parser.add_argument(
        'multiple1', type = int, nargs = '?',
        default = 3,
        help = 'First number of which multiples are to be added (default: 3)'
        )
    parser.add_argument(
        'multiple2', type = int, nargs = '?',
        default = 5,
        help= 'Second number of which multiples are to be added (default: 5)'
        )
    args = parser.parse_args()
    time = timeit(
        lambda: solve(args.upper_bound, args.multiple1, args.multiple2),
        number = 100)
    average_time = (time / 100) * 1e9 # Multiply by 1E9 to convert to nanoseconds
    result = solve(args.upper_bound, args.multiple1, args.multiple2)
    print(result)
    print(int(average_time))
