# Insertion sort implementation
# Steps:
# 1. Array lai sorted ra unsorted part ma divide garne
# 2. Unsorted part ko first element lai key manne
# 3. Key lai sorted part ma right position ma insert garne
# 4. Steps 2-3 repeat garne array sort nabhayesamma

def insertion_sort(arr):
    # First element lai sorted manera start garne
    for i in range(1, len(arr)):
        key = arr[i]  # Current element lai key manne
        j = i-1
        
        # Key vanda thula elements lai right shift garne
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        # Key lai usko right position ma rakhne
        arr[j + 1] = key
    
    return arr

# Example usage
if __name__ == "__main__":
    arr = [64, 34, 25, 12, 22, 11, 90]
    print("Sorted array:", insertion_sort(arr))
