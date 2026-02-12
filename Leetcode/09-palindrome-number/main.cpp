#include <iostream>
using namespace std;

bool isPalindrome(int x) {
    if (x < 0)
        return false;
    unsigned int temp = x;
    unsigned int palindromeNum = 0;
    while (x > 0) {
        palindromeNum *= 10;
        palindromeNum += x%10;
        x = x/10;
    }
    if (palindromeNum == temp)
        return true;
    else
        return false;
}

int main() {
    if (isPalindrome(121))
        cout << "true";
    else
        cout << "false";
}