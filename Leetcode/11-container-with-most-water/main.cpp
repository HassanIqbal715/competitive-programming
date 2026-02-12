#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int> height) {
    int start = 0;
    int end = height.size() - 1;
    int area = 0;
    int temp = 0;
    while (start < end) {
        temp = min(height[start], height[end]) * (end - start);
        if (temp > area) area = temp;
        if (height[start] < height[end]) start++;
        else end--;
    }
    return area;
}

int main() {
    cout << maxArea({1,8,6,2,5,4,1,3,1}) << endl;
}