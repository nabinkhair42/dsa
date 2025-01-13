# Factorial using Tail Recursion


def factorial_tail_recursive(n, accumulator=1):
    if n <= 1:
        return accumulator
    return factorial_tail_recursive(n - 1, n * accumulator)

print(factorial_tail_recursive(5)) 
