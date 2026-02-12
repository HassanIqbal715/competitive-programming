#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> numbers, int target) {
    int start = 0;
    int end = numbers.size() - 1;
    int sum = 0;
    while (start < end) {
        sum = numbers[start] + numbers[end];
        if (sum < target) {
            ++start;
        }
        else if (sum > target) {
            --end;
        }
        else {
            return {start, end};
        }
    }
    return {0, 0};
}

int main() {
    vector<int> result = twoSum({1, 2, 3, 4, 5}, 9);
    cout << result[0] << ' ' << result[1] << endl;
}