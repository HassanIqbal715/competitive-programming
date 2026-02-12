#include <stdio.h>

int largestAltitude(int* gain, int gainSize) {
    int current = 0;
    int max = 0;

    for (int i = 0; i < gainSize; i++) {
        current += gain[i];
        if (current > max)
            max = current;
    }

    return max;
}

int main() {
    int gain[5] = {-4, -3, -2, -1};
    printf("%d\n", largestAltitude(gain, 5));
    return 0;    
}