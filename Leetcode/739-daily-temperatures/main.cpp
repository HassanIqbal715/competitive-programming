#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> dailyTemperatures(vector<int> temperatures) {
    int n = temperatures.size();
    stack<int> stk;
    vector<int> result(n, 0);

    for (int i = n - 1; i >= 0; i--) {
        while(!stk.empty() && temperatures[stk.top()] <= temperatures[i])
            stk.pop();
        if (!stk.empty())
            result[i] = stk.top() - i;
        stk.push(i);
    }
    return result;
}

int main() {
    vector<int> result = dailyTemperatures({89,62,70,58,47,47,46,76,100,70});

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << '\n';
}