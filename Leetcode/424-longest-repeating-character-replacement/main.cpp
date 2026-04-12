#include <iostream>
#include <iostream>
#include <string>
#include <algorithm>

int characterReplacement(std::string s, int k) {
    if (s.empty()) return 0;

    int left = 0;
    int maxSize = 0;
    int mostFreq = 0;
    int f[26] = {0}; // Frequencies

    for (int right = 0; right < s.length(); right++) {
        int index = s[right] - 'A';
        f[index]++;
        mostFreq = std::max(mostFreq, f[index]);
        int windowSize = right - left + 1;
        if (windowSize - mostFreq > k) {
            f[s[left] - 'A']--;
            left++;
        }
        maxSize = std::max(maxSize, right - left + 1);
    }

    return maxSize;
}

int main() {
    std::cout << characterReplacement("ABBB", 1) << std::endl;
}
