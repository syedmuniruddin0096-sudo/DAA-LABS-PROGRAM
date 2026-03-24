#include <iostream>
using namespace std;

// Function to heapify a subtree
void heapify(int arr[], int n, int i) {
    int largest = i;        // root
    int left = 2*i + 1;     // left child
    int right = 2*i + 2;    // right child

    // Check left child
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Check right child
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If root is not largest
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify
        heapify(arr, n, largest);
    }
}

// Heap Sort function
void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements
    for (int i = n - 1; i > 0; i--) {
        // Swap root with last
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = 5;

    heapSort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
