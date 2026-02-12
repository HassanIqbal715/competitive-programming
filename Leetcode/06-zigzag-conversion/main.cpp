#include <iostream>
using namespace std;

string convert(string s, int numRows) {
    if (numRows == 1) return s;
    string res = "";
    int i = 0;
    bool flag = false;
    string temp = "";
    for (int k = 0; k < numRows; k++) {
        i = k;
        flag = false;
        temp = "";
        while(i < s.length()) {
            temp += s[i];
            if (k == 0 || k == numRows - 1) {
                i += (2*numRows - 2);
            }
            else if (!flag) {
                i += (2*numRows - 2*(k + 1));
                flag = true;
            }
            else {
                i += ((2*numRows - 2) - (2*numRows - 2*(k + 1)));
                flag = false;
            }
        }
        res += temp;
    }
    return res;
}

int main() {
    cout << convert("PAYPALISHIRING", 2);
}