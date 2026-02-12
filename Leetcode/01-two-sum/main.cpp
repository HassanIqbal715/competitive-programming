#include<vector>
#include<unordered_map>
#include<cmath>
#include<iostream>

std::vector<int> twoSum(std::vector<int> nums, int target) {
    std::unordered_map<int, std::vector<int>> m;
    std::unordered_map<int, std::vector<int>>::iterator it;
    for (int i = 0; i < nums.size(); i++) {
        if (m.count(nums[i])) {
            it = m.find(nums[i]);
            return {it->second[1], i};
        }
        else m.insert({target - nums[i], {nums[i], i}});
    }
    return {-1, -1};
}

int main() {
    std::vector<int> res = twoSum({3,2,4},6);
    for (int i = 0; i < 2; i++) std::cout<<res[i]<<"";
}