#include <iostream>
#include <vector>

// Partition the array and return the pivot index
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Choose the last element as the pivot
    int i = low - 1;        // Index of smaller element

    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            // Swap arr[i] and arr[j]
            std::swap(arr[i + 1], arr[j]);
            ++i;
        }
    }

    // Swap arr[i + 1] (pivot) and arr[high]
    std::swap(arr[i + 1], arr[high]);

    return i + 1;
}

// Quicksort algorithm
void quicksort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the sub-arrays
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

// Utility function to print an array
void printArray(const std::vector<int>& arr) {
    for (int element : arr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {7, 2, 1, 6, 8, 5, 3, 4};

    std::cout << "Original array: ";
    printArray(arr);

    quicksort(arr, 0, arr.size() - 1);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
