#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int> nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int j = 0;
    int k = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        
        j = i + 1;
        k = nums.size() - 1;
        while (j < k) {
            sum = nums[i] + nums[j] + nums[k];
            if (sum > 0) {
                k--;
            }
            else if (sum < 0) {
                j++;
            }
            else {
                res.push_back({nums[i], nums[j], nums[k]});
                j++;

                while (nums[j] == nums[j - 1] && j < k) {
                    j++;
                }
            }
        }
    }
    return res;
}

int main() {
    vector<vector<int>> result = threeSum({-1, 0, 1, 2, -1, -4});
}