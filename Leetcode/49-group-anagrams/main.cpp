#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> strs) {
    unordered_map<string, vector<string>> map;

    int n = strs.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        vector<int> myCount(26, 0);
        for (int j = 0; j < strs[i].length(); j++) {
            myCount[strs[i][j] - 'a']++;
        }

        string key = to_string(myCount[0]);
        for (int i = 1; i < 26; i++) {
            key += ',' + to_string(myCount[i]);
        }
        map[key].push_back(strs[i]);
    }
    
    vector<vector<string>> result;
    for (auto it = map.begin(); it != map.end(); it++) {
        result.push_back(it->second);
    }

    return result;
}

int main() {
    vector<vector<string>> result = groupAnagrams({"eat","tea","tan","ate","nat","bat"});

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << "\n";
    }
}