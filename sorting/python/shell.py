# Shell sort implementation using gap sequences
# Steps:
# 1. Array lai gap size ma divide garne
# 2. Gap size ko elements lai insertion sort jastai sort garne
# 3. Gap size lai half gardai sort garne
# 4. Gap size 1 vayesi insertion sort complete hunxa

def shell_sort(arr):
    n = len(arr)
    gap = n // 2    # Initial gap size array ko half
    
    while gap > 0:  # Gap 0 navayesamma continue garne
        # Gap position bata start garera array ko end samma traverse
        for i in range(gap, n):
            temp = arr[i]
            j = i
            # Gap difference ko elements compare garera sort garne
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2   # Gap size lai half garne
    return arr

# Example usage
if __name__ == "__main__":
    arr = [64, 34, 25, 12, 22, 11, 90]
    print("Sorted array:", shell_sort(arr))
