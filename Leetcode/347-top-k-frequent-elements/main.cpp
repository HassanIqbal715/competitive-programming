#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> topKFrequent(vector<int> nums, int k) {
    unordered_map<int, int> map;

    priority_queue<int> pq;

    for (int i = 0; i < nums.size(); i++) {
        map[nums[i]]++;
    }

    int max = map[nums[0]];
    int arr[2] = {nums[0], max};

    vector<int> result;

    for (int j = 0; j < k; j++) {
        for (auto it = map.begin(); it != map.end(); it++) {
            if (it->second > max) {
                max = it->second;
                arr[0] = it->first;
                arr[1] = max;
            }
        }
        result.push_back(arr[0]);
        map[arr[0]] = 0;
        max = 0;
    }

    return result;
}

int main() {
    vector<int> res = topKFrequent({1,1,1,2,2,3}, 2);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}