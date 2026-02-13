#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int> heights) {
    int n = heights.size();
    vector<int> suffix(n);
    vector<int> prefix(n);
    
    prefix[0] = heights[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = max(prefix[i - 1], heights[i]);
    }

    suffix[n - 1] = heights[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = max(heights[i], suffix[i + 1]);
    }

    int maxWater = 0;
    int localWater = 0;
    for (int i = 0; i < n; i++) {
        localWater = min(suffix[i], prefix[i]) - heights[i];
        if (localWater > 0)
            maxWater += localWater;
    }

    return maxWater;
}

int main() {
    cout << trap({4,2,0,3,2,5}) << endl;
}