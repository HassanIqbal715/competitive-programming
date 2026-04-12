#include <iostream>
#include <vector>

int minSubArrayLen(int target, std::vector<int>& nums) {
    int currentSum = 0;
    int minSize = nums.size() + 1;
    int left = 0;
    int currentSize = 0;
    bool found = false;

    for (int i = 0; i < nums.size(); i++) {
        if (currentSum < target) {
            currentSum += nums[i];
            currentSize++;
        }
        while (currentSum >= target) {
            if (currentSize < minSize) {
                minSize = currentSize;
                found = true;
            }
            currentSum -= nums[left];
            currentSize--;
            left++;
        }
    }

    if (!found) return 0;
    return minSize;
}

int main() {
    std::vector<int> input = {1, 1, 1, 1, 1, 1, 1, 1};
    std::cout << minSubArrayLen(11, input) << '\n';
}