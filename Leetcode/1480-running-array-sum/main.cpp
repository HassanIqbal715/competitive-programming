#include <vector>
#include <iostream>

std::vector<int> runningSum(std::vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) {
        nums[i] = nums[i - 1] + nums[i];
    }
    return nums;
}

int main() {
    std::vector<int> nums = {2};

    std::vector<int> output = runningSum(nums);

    for (int i = 0; i < output.size(); i++) {
        std::cout << output[i] << " ";
    }

    std::cout << "\n";

    return 0;
}