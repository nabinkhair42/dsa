# Radix sort implementation using counting sort
# Steps:
# 1. Sabai numbers ko digits check garne
# 2. Least significant digit bata sort garne
# 3. Most significant digit samma sort gardai jane
# 4. Counting sort use garera each digit lai sort garne

def counting_sort(arr, exp):
    n = len(arr)
    output = [0] * n    # Result rakhne array
    count = [0] * 10    # Digits 0-9 ko count rakhne

    # Current digit ko frequency count garne
    for i in range(n):
        index = arr[i] // exp
        count[index % 10] += 1

    # Count array lai cumulative sum ma convert garne
    for i in range(1, 10):
        count[i] += count[i - 1]

    # Output array ma elements lai right position ma rakhne
    i = n - 1
    while i >= 0:
        index = arr[i] // exp
        output[count[index % 10] - 1] = arr[i]
        count[index % 10] -= 1
        i -= 1

    # Original array lai output array sanga update garne
    for i in range(n):
        arr[i] = output[i]

def radix_sort(arr):
    max_num = max(arr)  # Maximum number find garne
    exp = 1
    # Jaba samma maximum number ko digitssakidaina
    while max_num // exp > 0:
        counting_sort(arr, exp)
        exp *= 10       # Next digit ma jane
    return arr

# Example usage
if __name__ == "__main__":
    arr = [170, 45, 75, 90, 802, 24, 2, 66]
    print("Sorted array:", radix_sort(arr))
