#include <iostream>
#include <vector>
#include <string>
using namespace std;

string encode(vector<string> strs) {
    string output;

    for (int i = 0; i < strs.size(); i++) {
        output += "#";
        output += to_string(strs[i].length());
        output += "#";
        output += strs[i];
    }

    return output;
}

vector<string> decode(string s) {
    int tempLen = 0;
    vector<string> output;
    for (int i = 0; i < s.length(); i++) {
        tempLen = 0;
        if (s[i] == '#') {
            ++i;
            while (s[i] != '#') {
                tempLen *= 10;
                tempLen += (s[i] - '0');
                ++i;
            }
            output.push_back(s.substr(i + 1, tempLen));
            i += tempLen;
        }
    }
    return output;
}

int main() {
    string input = encode({"neet","code","love","you"});
    vector<string> result = decode(input);
    cout << input << '\n';
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << '\n';
}