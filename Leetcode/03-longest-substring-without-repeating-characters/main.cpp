#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> characters;
    int left = 0;
    int longest = 0;
    int current = 0;

    for (int i = 0; i < s.length(); i++) {
        if (characters[s[i]] == 0) {
            characters[s[i]] = 1;
            current++;
        }
        else {
            while (characters[s[i]] == 1) {
                characters[s[left]] = 0;
                left++;
                current--;
            }
            if (characters[s[i]] == 0) current++;
            characters[s[i]] = 1;
        }
        longest = (longest > current) ? longest : current;
    }
    return longest;
}

int main() {
    cout << lengthOfLongestSubstring("dvdf") << '\n';
}
