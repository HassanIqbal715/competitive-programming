#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, int> map;
    int n = nums.size();
    
    for (int i = 0; i < n; i++) {
        if (map.count(nums[i]))
            return true;
        else
            map.insert(pair<int, int>(nums[i], 1));
    }

    return false;
}

int main() {
    vector<int> nums = {1, 2, 3, 1, 2, 2, 2, 2};
    cout << containsDuplicate(nums) << endl;
}