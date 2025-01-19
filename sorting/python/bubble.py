# Bubble sort implementation
# Steps:
# 1. Adjacent elements compare garne
# 2. Left element right element vanda thulo xa vane swap garne
# 3. Array ko end samma steps 1-2 repeat garne
# 4. Array sort nabhayesamma steps 1-3 repeat garne

def bubble_sort(arr):
    n = len(arr)
    
    # Outer loop for n-1 passes
    for i in range(n):
        # Inner loop for comparison in each pass
        for j in range(0, n-i-1):
            # Adjacent elements compare garne
            if arr[j] > arr[j+1]:
                # Thulo element lai right shift garne
                arr[j], arr[j+1] = arr[j+1], arr[j]
    
    return arr

# Example usage
if __name__ == "__main__":
    arr = [64, 34, 25, 12, 22, 11, 90]
    print("Sorted array:", bubble_sort(arr))
