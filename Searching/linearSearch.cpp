#include <iostream>
#include <vector>

// Linear Search algorithm
int linearSearch(const std::vector<int>& arr, int target) {
    int n = arr.size();

    for (int i = 0; i < n; ++i) {
        if (arr[i] == target) {
            return i;  // Return the index where the target element is found
        }
    }

    return -1;  // Return -1 if the target element is not found
}

int main() {
    std::vector<int> arr = {7, 2, 1, 6, 8, 5, 3, 4};
    int target = 5;

    int index = linearSearch(arr, target);

    if (index != -1) {
        std::cout << "Element " << target << " found at index " << index << std::endl;
    } else {
        std::cout << "Element " << target << " not found in the array" << std::endl;
    }

    return 0;
}
