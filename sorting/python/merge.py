# Merge sort implementation using divide and conquer
# Steps:
# 1. Array lai 2 parts ma divide garne
# 2. Left ra right parts lai recursively sort garne
# 3. Sorted parts lai merge garne
# 4. Final sorted array paune

def merge_sort(arr):
    if len(arr) <= 1:   # Base case: 1 or 0 elements already sorted
        return arr
    
    # Array lai 2 parts ma divide garne
    mid = len(arr) // 2
    left = arr[:mid]    # Left half
    right = arr[mid:]   # Right half
    
    # Recursively both parts lai sort garne
    merge_sort(left)
    merge_sort(right)
    
    # Merge process ko lagi pointers
    i = j = k = 0
    
    # Left ra right parts lai merge garne process
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            arr[k] = left[i]
            i += 1
        else:
            arr[k] = right[j]
            j += 1
        k += 1
    
    # Baki raheko left part lai add garne
    while i < len(left):
        arr[k] = left[i]
        i += 1
        k += 1
    
    # Baki raheko right part lai add garne
    while j < len(right):
        arr[k] = right[j]
        j += 1
        k += 1
    
    return arr

# Example usage
if __name__ == "__main__":
    arr = [64, 34, 25, 12, 22, 11, 90]
    print("Sorted array:", merge_sort(arr))
