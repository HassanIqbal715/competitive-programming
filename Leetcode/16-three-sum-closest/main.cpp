#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int threeSumClosest(vector<int> nums, int target) {
    int closest = 10000;
    sort(nums.begin(), nums.end());

    int j = 0;
    int k = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i > 1 && nums[i] == nums[i - 1]) {
            continue;
        }

        j = i + 1;
        k = nums.size() - 1;

        while (j < k) {
            sum = nums[i] + nums[j] + nums[k];
            
            if (abs(target - sum) < abs(target - closest)) {
                closest = sum;
            }
            if (sum > target) {
                k--;
            }
            else if (sum < target) {
                j++;
            }
            else {
                return sum;
            }
        }
    }
    return closest;
}

int main() {
    cout << threeSumClosest({-1, 2, 1, -4}, 1) << endl;
}