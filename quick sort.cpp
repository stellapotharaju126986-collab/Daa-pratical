#include <iostream>
#include <utility> // For std::swap

// This function takes the last element as pivot, places
// the pivot element at its correct position in sorted
// array, and places all smaller elements to the left
// of the pivot and all greater elements to the right.
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = (low - 1);    // Index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++; // Increment index of the smaller element
            std::swap(arr[i], arr[j]);
        }
    }
    // Swap the pivot element with the element at (i + 1)
    std::swap(arr[i + 1], arr[high]);
    return (i + 1); // Return the partitioning index
}

// The main function that implements QuickSort
// low  --> Starting index,
// high --> Ending index
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[p] is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    std::cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
