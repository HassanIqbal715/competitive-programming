#include <iostream>
#include <cmath>
using namespace std;

double myPow(double x, int n) {
    double result = x;
    if (n == 0 || x == 1)
        return 1;
    if (x == -1) {
        if (n%2 == 0)
            return 1;
        else 
            return -1;
    }
    long long int abs_n = abs(n);
    for (long long int i = 1; i < abs_n; i++) {
        result *= x;
    }
    if (n < 0)
        return double(1)/result;
    else 
        return result;  
}

int main() {
    cout << myPow(-3, 5);
}