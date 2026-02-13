#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestConsecutiveSequence(vector<int> nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());

        int longest = 0;

        for (int num : numSet) {
            if (numSet.find(num - 1) == numSet.end()) {
                int length = 1;
                while (numSet.find(num + length) != numSet.end()) {
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
}

int main() {
    cout << longestConsecutiveSequence({100, 4, 200, 1, 2, 3, 2});
}