#include <iostream>
#include <vector>
#include <limits>

int maxSubArray(std::vector<int> nums) {
    int sum = 0;
    int maxSum = -2147483648;
    for (int i = 0; i < nums.size(); i++) {
        if (sum < 0 && nums[i] > sum)
            sum = nums[i];
        else
            sum += nums[i];
        if (sum > maxSum) {
            maxSum = sum;
        }
    }
    return maxSum;
}

int main() {
    std::cout << maxSubArray({2,-3,4,-2,2,1,-1,4});
}