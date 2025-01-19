# Selection sort implementation
# Steps:
# 1. Array lai unsorted ra sorted region ma divide garne
# 2. Unsorted region bata minimum element find garne
# 3. Minimum element lai sorted region ko end ma rakhne
# 4. Steps 2-3 repeat garne array sort nabhayesamma

def selection_sort(arr):
    n = len(arr)
    
    # Outer loop for traversing through n-1 elements
    for i in range(n):
        # Minimum element ko index store garne
        min_idx = i
        
        # Unsorted part bata minimum element khojne
        for j in range(i+1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        
        # Minimum element lai current position ma swap garne
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    
    return arr

# Example usage
if __name__ == "__main__":
    arr = [64, 34, 25, 12, 22, 11, 90]
    print("Sorted array:", selection_sort(arr))
