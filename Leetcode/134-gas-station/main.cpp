#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int> gas, vector<int> cost) {
    int n = gas.size();
    int runningSum = 0;
    int currSum = 0;
    int index = 0;

    for (int i = 0; i < n; i++) {
        currSum += (gas[i] - cost[i]);
        if (currSum < 0) {
            runningSum += currSum;
            currSum = 0;
            index = i + 1;
        }
    }

    if (currSum + runningSum >= 0) {
        return index;
    }
    else {
        return -1;
    }
}

int main() {
    cout << canCompleteCircuit({3, 1, 1}, {1, 2, 2}) << endl;
}