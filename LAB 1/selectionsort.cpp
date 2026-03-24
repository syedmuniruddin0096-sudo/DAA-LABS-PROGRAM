#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = 5;

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        // Find the smallest element
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    // Print sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}