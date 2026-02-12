#include <iostream>
using namespace std;

// This problem follows the fibonacci sequence to calculate the number of steps.
int climbStairs(int n) {
    int fib1 = 1;
    int fib2 = 2;
    int iterations = n/2;
    if (n%2 == 0)
        iterations--;

    for (int i = 0; i < iterations; i++) {
        fib1 += fib2;
        fib2 += fib1;
    }
    if (n%2 == 0)
        return fib2;
    else
        return fib1;
}

int main() {
    cout << climbStairs(10);
}