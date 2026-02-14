#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int carFleet(int target, vector<int> position, vector<int> speed) {
    int n = position.size();

    vector<pair<int, int>> cars;
    for (int i = 0; i < n; i++) {
        cars.push_back(make_pair(position[i], speed[i]));
    }

    sort(cars.begin(), cars.end(), greater<pair<int, int>>());

    stack<double> stk;

    for (int i = 0; i < n; i++) {
        int pos = cars[i].first;
        int spd = cars[i].second;
        double timeTaken = (double)(target - pos) / spd;

        if (stk.empty() || timeTaken > stk.top()) {
            stk.push(timeTaken);
        }
    }

    return stk.size();
}

int main() {
    cout << carFleet(12, {10, 8, 0, 5, 3}, {2, 4, 1, 1, 3}) << endl;
}