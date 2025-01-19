# Quick sort implementation using partition
# Steps:
# 1. Pivot element choose garne (last element)
# 2. Pivot vanda sana elements left ma rakhne
# 3. Pivot vanda thula elements right ma rakhne
# 4. Left ra right part lai recursively sort garne

def partition(arr, low, high):
    pivot = arr[high]   # Last element lai pivot manne
    i = low - 1        # Smaller elements ko index
    
    # Pivot vanda sana elements lai left side ma rakhne
    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    
    # Pivot lai usko final position ma rakhne
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def quick_sort(arr, low, high):
    if low < high:
        # Partition garera pivot ko position paune
        pi = partition(arr, low, high)
        # Left part lai recursively sort garne
        quick_sort(arr, low, pi - 1)
        # Right part lai recursively sort garne
        quick_sort(arr, pi + 1, high)
    return arr

# Example usage
if __name__ == "__main__":
    arr = [64, 34, 25, 12, 22, 11, 90]
    n = len(arr)
    print("Sorted array:", quick_sort(arr, 0, n-1))
