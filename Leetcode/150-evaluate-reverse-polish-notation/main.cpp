#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int evalRPN(vector<string> tokens) {
    stack<int> stk;
    int temp = 0;

    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i] == "+") {
            temp = stk.top();
            stk.pop();
            temp += stk.top();
            stk.pop();
            stk.push(temp);
        }
        else if (tokens[i] == "-") {
            temp = stk.top();
            stk.pop();
            temp = stk.top() - temp;
            stk.pop();
            stk.push(temp);
        }
        else if (tokens[i] == "*") {
            temp = stk.top();
            stk.pop();
            temp *= stk.top();
            stk.pop();
            stk.push(temp);
        }
        else if (tokens[i] == "/") {
            temp = stk.top();
            stk.pop();
            temp = stk.top() / temp;
            stk.pop();
            stk.push(temp);
        }
        else {
            stk.push(stoi(tokens[i]));
        }
    }

    return stk.top();
}

int main() {
    cout << evalRPN({"4","13","5","/","+"}) << endl;
}