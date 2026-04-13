#include <iostream>
#include <vector>
#include <algorithm>

bool canJump(std::vector<int> nums) {
    if (nums.size() == 0) return true;
    int n = nums.size();
    int goal = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        if (i + nums[i] >= goal)
            goal = i;
    }
    return (goal == 0);
}

int main() {
    std::cout << canJump({1, 2, 0, 1, 0});
}