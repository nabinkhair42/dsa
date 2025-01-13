# Iterative GCD
def gcd_iterative(a, b):
    while b != 0:
        a, b = b, a % b
    return a

# Example usage
print(gcd_iterative(48, 18))  # Output: 6
