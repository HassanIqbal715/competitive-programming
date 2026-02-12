#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.length() != t.length()) return false;
    
    unordered_map<char, int> map;
    
    for (int i = 0; i < s.length(); i++) {
        map[s[i]] += 1;
        map[t[i]] -= 1;
    }

    for (auto it = map.begin(); it != map.end(); it++) {
        if (it->second != 0)
            return false;
    }

    return true;
}

int main() {
    cout << isAnagram("racecar", "rcearas");
}