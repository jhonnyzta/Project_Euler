from timeit import timeit

def brute() -> int:
    accumulator = 0
    for i in range(1, 1000):
        if i % 3 == 0 or i % 5 == 0:
            accumulator += i
    return accumulator

result = brute()
time = timeit(lambda: brute(), number = 100)
average_time = int((time / 100) * 1e9)
print(result)
print(average_time)
