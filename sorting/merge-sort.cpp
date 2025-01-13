// mergesort.cpp
#include <iostream>
using namespace std;
void merge(int arr[], int l, int mid, int r)
{
int s1 = (mid - l) + 1;
int s2 = r - mid;
int a1[s1];
int a2[s2];
for (int i = 0; i < s1; i++)
{
    a1[i]=arr[l+i];
}
for (int i = 0; i < s2; i++)
{
    a2[i]=arr[mid + 1 + i];
}
int i = 0;
int j = 0;
int k = l;
while (i < s1 && j < s2)
{
    if (a1[i] < a2[j])
    {
        arr[k] = a1[i];
        k=k+1;
        i=i+1;
    }
    else
    {
        arr[k++] = a2[j++];
        k=k+1;
        j=j+1;
    }
}
while (i < s1)
{
    arr[k++] = a1[i++];
}
while (j < s2)
{
    arr[k++] = a2[j++];
}
}
void mergeSort(int arr[], int l, int r)
{
if (l >= r)
    return;
int mid = l + (r - l) / 2;
mergeSort(arr, l, mid);
mergeSort(arr, mid + 1, r);
merge(arr, l, mid, r);
}
int main()
{
int arr[]={7, 2, 1, 5, 3, 6, 7};
int n=sizeof(arr)/sizeof(arr[0]);
mergeSort(arr, 0, n - 1);
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
}
