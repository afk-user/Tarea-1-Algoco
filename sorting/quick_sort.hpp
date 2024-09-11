// O(nlogn), basado en algoritmo de geeksforgeeks.org
#include <bits/stdc++.h>
using namespace std;

// Funcion para particionar el arreglo y retornar el indice del pivote
int partition(vector<int>& arr, int low, int high) {
  
    // Elegir el pivote por medio de la mediana de 3
    int pos;
    int mid = (low+high)/2;
    if ((arr[low]>arr[mid])^(arr[low]>arr[high]))
        pos = low;
    else if ((arr[mid]<arr[low])^(arr[mid]<arr[high]))
        pos = mid;
    else
        pos = mid;
    
    // se asigna el valor del pivote y moverlo al final
    int pivot = arr[pos];
    swap(arr[pos],arr[high]);
  
    // Indice del valor más pequeño y 
    //la posicion correcta del pivote encontrado
    int i = low - 1;

    // Moverse en arr[low..high] y mover todos los elementos menores a la izquierda
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    // Mover el pivote al lado del valor más alto menor al pivote y luego retornarlo
    swap(arr[i + 1], arr[high]);  
    return i + 1;
}

// La implementación de Quicksort
void quickSort(vector<int>& arr, int low, int high) {
  
    if (low < high) {
      
        // Pivote
        int pi = partition(arr, low, high);

        // Recursion para la mitad menor al pivote
        // y la mitad mayor o igual al pivote
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}