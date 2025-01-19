# Heap sort implementation
# Steps:
# 1. Array lai max heap ma convert garne
# 2. Root element lai last ma swap garne
# 3. Heap size decrease garera heapify garne
# 4. Steps 2-3 repeat garne array sort nabhayesamma

def heapify(arr, n, i):
    largest = i        # Root lai largest manne
    left = 2 * i + 1  # Left child
    right = 2 * i + 2 # Right child
    
    # Left child root vanda thulo xa ki check garne
    if left < n and arr[left] > arr[largest]:
        largest = left
    
    # Right child root vanda thulo xa ki check garne
    if right < n and arr[right] > arr[largest]:
        largest = right
    
    # Root largest xaina vane swap garne
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        # Affected subtree lai heapify garne
        heapify(arr, n, largest)

def heap_sort(arr):
    n = len(arr)
    
    # Max heap build garne
    for i in range(n//2 - 1, -1, -1):
        heapify(arr, n, i)
    
    # Element lai ek ek garera heap bata nikalne
    for i in range(n-1, 0, -1):
        arr[0], arr[i] = arr[i], arr[0]  # Swap root with last element
        heapify(arr, i, 0)
    
    return arr

# Example usage
if __name__ == "__main__":
    arr = [64, 34, 25, 12, 22, 11, 90]
    print("Sorted array:", heap_sort(arr))
