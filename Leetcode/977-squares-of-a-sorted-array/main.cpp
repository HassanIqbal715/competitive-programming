#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// Function to get the maximum value in the array
int getMax(const std::vector<int>& arr) {
    int maxVal = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// A function to do counting sort of arr[] according to the digit represented by exp.
void countSort(std::vector<int>& arr, int exp) {
    int n = arr.size();
    std::vector<int> output(n, 0);
    std::vector<int> count(10, 0); // Base 10 for digits 0-9

    // Store count of occurrences of each digit
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // Change count[i] so that it contains the actual
    // position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array. Iterate from the end to maintain stability.
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to the current digit
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// The main function to implement Radix Sort
void radixSort(std::vector<int>& arr) {
    // Find the maximum number to know the number of digits
    int m = getMax(arr);

    // Do counting sort for every digit. Note that instead of
    // passing digit number, exp is passed. exp is 10^i
    // where i is the current digit number (units, tens, hundreds, etc.)
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(arr, exp);
    }
}

vector<int> sortedSquares(vector<int> nums) {
    vector<int> newArr;

    for (int i = 0; i < nums.size(); i++) {
        newArr.push_back(nums[i] * nums[i]);
    }

    radixSort(newArr);

    return newArr;
}

// Two types of participants in GSoC
// Umbrella organisations. Uske andar aur aa jati hain. LLVM. Aap dekh sakte ho uske andar kitni organisations ati hain
// Aik Standalone hoti hain. 

int main() {
    vector<int> sq = sortedSquares({-5, -1, -1, 1, 5});

    for (int i = 0; i < sq.size(); i++) {
        cout << sq[i] << " ";
    }

    cout << '\n';

    return 0;
}