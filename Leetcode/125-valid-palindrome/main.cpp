#include <iostream>
#include <vector>
using namespace std;

bool isAlphaNum(char c) {
    return (
        (c >= 'A' && c <= 'Z') || 
        (c >= 'a' && c <= 'z') || 
        (c >= '0' && c <= '9')
    );
}

bool isPalindrome(string s) {
    int l = 0;
    int r = s.length() - 1;
    while (l < r) {
        if (!isAlphaNum(s[l])) {
            l++;
            continue;
        }
        if (!isAlphaNum(s[r])) {
            r--;
            continue;
        }
        if (s[l] >= 'A' && s[l] <= 'Z') s[l] += 32;
        if (s[r] >= 'A' && s[r] <= 'Z') s[r] += 32;
        if (s[l] != s[r]) { 
            cout << s[l] << " " << s[r];
            return false;
        }
        l++;
        r--;
    }
    return true;
}

int main() {
    cout << isPalindrome("A man, a plan, a canal: Panama") << endl;
}