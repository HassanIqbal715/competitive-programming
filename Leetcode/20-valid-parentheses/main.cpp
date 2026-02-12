#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> Stk;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            Stk.push(s[i]);
        }
        else if (s[i] == ')') {
            if (Stk.size() > 0) {
                if (Stk.top() == '(')
                    Stk.pop();
                else 
                    return false;
            }
            else {
                return false;
            }
        }
        else if (s[i] == '}') {
            if (Stk.size() > 0) {
                if (Stk.top() == '{')
                    Stk.pop();
                else 
                    return false;
            }
            else {
                return false;
            }
        }
        else if (s[i] == ']') {
            if (Stk.size() > 0) {
                if (Stk.top() == '[')
                    Stk.pop();
                else 
                    return false;
            }
            else {
                return false;
            }
        }
    }
    if (Stk.size() == 0)
        return true;
    else
        return false;
}

int main() {
    if (isValid("){}[]")) {
        cout << "VALUD";
    }
    else {
        cout << "NOT SO VALID";
    }
}