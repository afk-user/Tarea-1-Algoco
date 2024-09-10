    // O(nlogn), extraido de geeksforgeeks.org
#include <bits/stdc++.h>
using namespace std;

// Function to partition the array and return the pivot index
int partition(vector<int>& arr, int low, int high) {
  
    // Choose the pivot
    int pos;
    int mid = (low+high)/2;
    if ((arr[low]>arr[mid])^(arr[low]>arr[high]))
        pos = low;
    else if ((arr[mid]<arr[low])^(arr[mid]<arr[high]))
        pos = mid;
    else
        pos = mid;
    
    int pivot = arr[pos];
    swap(arr[pos],arr[high]);
  
    // Index of smaller element and indicates 
    // the right position of pivot found so far
    int i = low - 1;

    // Traverse arr[low..high] and move all smaller
    // elements on left side. Elements from low to 
    // i are smaller after every iteration
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    // Move pivot after smaller elements and
    // return its position
    swap(arr[i + 1], arr[high]);  
    return i + 1;
}

// The QuickSort function implementation
void quickSort(vector<int>& arr, int low, int high) {
  
    if (low < high) {
      
        // pi is the partition return index of pivot
        int pi = partition(arr, low, high);

        // Recursion calls for smaller elements
        // and greater or equals elements
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}