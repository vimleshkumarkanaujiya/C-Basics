#include <iostream>
#include <vector>

// Binary Search algorithm
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;  // Return the index where the target element is found
        } else if (arr[mid] < target) {
            left = mid + 1;  // Target element is in the right half
        } else {
            right = mid - 1;  // Target element is in the left half
        }
    }

    return -1;  // Return -1 if the target element is not found
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    int target = 5;

    int index = binarySearch(arr, target);

    if (index != -1) {
        std::cout << "Element " << target << " found at index " << index << std::endl;
    } else {
        std::cout << "Element " << target << " not found in the array" << std::endl;
    }

    return 0;
}
