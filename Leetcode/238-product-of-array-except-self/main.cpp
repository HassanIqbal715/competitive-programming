#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int> nums) {
    // vector<int> prefixProd(nums.size());
    // prefixProd[0] = 1;
    // int temp = 1;
    // for (int i = 1; i < nums.size(); i++) {
    //     temp *= nums[i - 1];
    //     prefixProd[i] = temp;
    // }

    // vector<int> suffixProd(nums.size());
    // temp = 1;
    // suffixProd[nums.size() - 1] = 1;
    // for (int i = nums.size() - 2; i >= 0; i--) {
    //     temp *= nums[i + 1];
    //     suffixProd[i] = temp;
    // }

    // vector<int> result(nums.size());
    // for (int i = 0; i < nums.size(); i++) {
    //     result[i] = prefixProd[i] * suffixProd[i];
    // }

    // return result;

    vector<int> result(nums.size());
    int temp = 1;
    result[0] = 1;
    for (int i = 1; i < nums.size(); i++) {
        temp *= nums[i - 1];
        result[i] = temp;
    }
    temp = 1;
    for (int i = nums.size() - 2; i >= 0; i--) {
        temp *= nums[i + 1];
        result[i] *= temp;
    }
    return result;
}

int main() {
    vector<int> result = productExceptSelf({1, 2, 3, 4});

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}