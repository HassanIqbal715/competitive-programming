#include <iostream>
#include <string>
#include <unordered_map>

std::string minWindow(std::string s, std::string t) {
    std::unordered_map<char, int> targets;
    int targetsCount = 0;
    // store the target characters along with the required count
    for (int i = 0; i < t.length(); i++) {
        targets[t[i]]++;
        targetsCount++;
    }

    int left = 0;
    int right = 0;

    int currSize = 0;
    std::unordered_map<char, int> matches;

    // traverse the string s to determine left
    for (int i = 0; i < s.length(); i++) {
        if (targets[s[i]]) {
            left = i;
            targetsCount--;
            currSize = 1;
            matches.insert(std::make_pair(s[i], 1));
            break;
        }
    }

    // No matches
    if (currSize == 0) return "";
    if (targetsCount == 0) return std::string(1, s[left]);

    int minSize = 2147483647; // MAX
    int minLeft = 0;
    int minRight = 0;
    
    // traverse beyond to find the substring
    for (right = left + 1; right < s.length(); right++) {
        currSize++;
        if (!targets[s[right]]) {
            continue;
        }

        if (targets[s[right]] <= matches[s[right]]) {
            if (s[left] == s[right]) {
                left++;
                currSize--;
                while (!targets[s[left]] || matches[s[left]] > targets[s[left]])
                {
                    if (matches[s[left]]) {
                        matches[s[left]]--;
                    }
                    left++;
                    currSize--;
                }
                matches[s[right]]--;
            }
        }
        else {
            targetsCount--;
        }
        matches[s[right]]++;
        if (currSize < minSize && targetsCount == 0) {
            minSize = currSize;
            minLeft = left;
        }
    }

    if (targetsCount > 0) return "";
    return s.substr(minLeft, minSize);
}

int main() {
    std::cout << minWindow("ab", "a") << '\n';
}