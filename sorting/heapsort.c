// implementation of heapsort using c
// Steps:
// 1. max heap banaune given array bata
// 2. root element lai last element banaune
// 3. root element lai heapify garna
// 4. 2nd step and 3rd step repeat garna


#include <stdio.h>

void heapify(int arr[], int n, int i)
{
    int largest = i; // root lai largest manne
    int l = 2 * i + 1; // left child ko index
    int r = 2 * i + 2;  // right child ko index

    // left child root vanda thulo xa vane largest lai left child banaune
    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }

    // right child root vanda thulo xa vane largest lai right child banaune
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        //  recursively heapify garne affect vako subtree lai
        heapify(arr, n, largest);
    }
}

//  array lai sort garaune
void heapSort(int arr[], int n)
{
    // First: max heap banaune
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i); //  heapifu garera max heap banaune
    }

    // root element lai last element ma rakhne
    for (int i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        // heapify garera baki array lai max heap banaune
        heapify(arr, i, 0);
    }
}


int main()
{
    int arr[] = {7, 2, 1, 5, 3, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    heapSort(arr, n);

    // sorted array print garna
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}