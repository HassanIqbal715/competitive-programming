#include <iostream>
using namespace std;

int romanToInt(string s) {
    int sum = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == 'I')
            sum += 1;
        else if (s[i] == 'V') {
            sum += 5;
            if (i != 0) {
                if (s[i - 1] == 'I') {
                    sum -= 1;
                    --i;
                    continue;
                }
            }
        }
        else if (s[i] == 'X') {
            sum += 10;
            if (i != 0) {
                if (s[i - 1] == 'I') {
                    sum -= 1;
                    --i;
                    continue;
                }
            }
        }
        else if (s[i] == 'L') {
            sum += 50;
            if (i != 0) {
                if (s[i - 1] == 'X') {
                    sum -= 10;
                    --i;
                    continue;
                }
            }
        }
        else if (s[i] == 'C') {
            sum += 100;
            if (i != 0) {
                if (s[i - 1] == 'X') {
                    sum -= 10;
                    --i;
                    continue;
                }
            }
        }
        else if (s[i] == 'D') {
            sum += 500;
            if (i != 0) {
                if (s[i - 1] == 'C') {
                    sum -= 100;
                    --i;
                    continue;
                }
            }
        }
        else if (s[i] == 'M') {
            sum += 1000;
            if (i != 0) {
                if (s[i - 1] == 'C') {
                    sum -= 100;
                    --i;
                    continue;
                }
            }
        }
    }
    return sum;
}

int main() {
    cout << romanToInt("LVIII");
}