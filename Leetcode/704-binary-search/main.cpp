#include <iostream>
#include <vector>

int search(std::vector<int> nums, int target) {
    int mid = (nums.size() - 1) / 2;
    int left = 0;
    int right = nums.size() - 1;

    do {
        if (target < nums[mid]) {
            right = mid;
            mid = (left + right - 1) / 2;
        }
        else if (target > nums[mid]) {
            left = mid;
            mid = (left + right + 1) / 2;
        }
        if (target == nums[mid]) {
            return mid;
        }
    } while (left < right - 1);

    return -1;
}

int main() {
    std::cout << "Result: " << search({-1, 0, 3, 5, 9, 12}, 3);
}
