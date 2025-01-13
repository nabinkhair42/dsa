# nth Fibonacci Term using Recursion with Memoization

memo = {}

def fibonacci_memo(n):
    if n in memo:
        return memo[n]
    if n <= 1:
        return n
    memo[n] = fibonacci_memo(n - 1) + fibonacci_memo(n - 2)
    return memo[n]

print(fibonacci_memo(9)) 
