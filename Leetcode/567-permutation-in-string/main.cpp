#include <iostream>
#include <unordered_map>
using namespace std;

bool checkInclusion(string s1, string s2) {
    if(s1.length() > s2.length()) return false;

    unordered_map<char, int> map1;
    unordered_map<char, int> map2;

    for (int i = 0; i < s1.length(); i++) {
        map1[s1[i]]++;
        map2[s2[i]]++;
    }

    int left = 0;
    int right = s1.length() - 1;
    char c = s2[0];
    bool found = true;

    for (int i = right; i < s2.length(); i++) {
        found = true;
        if (map1 == map2) return true;
        map2[s2[++right]]++;
        if (--map2[s2[left]] == 0) map2.erase(s2[left]);
        left++;
    }
    return false;
}

int main() {
    cout << checkInclusion("ab", "eidbaoo") << '\n';
}