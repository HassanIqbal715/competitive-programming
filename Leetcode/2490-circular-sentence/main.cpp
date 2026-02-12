#include <iostream>
using namespace std;

bool isCircularSentence(string sentence) {
    if (sentence[0] != sentence[sentence.size() - 1]) {
        return false;
    }
    for (int i = 0; i < sentence.size(); i++) {
        if (sentence[i] == ' ') {
            if (sentence[i - 1] >= 'A' && sentence[i - 1] <= 'Z') {
                sentence[i - 1] += 32;
            }
            if (sentence[i + 1] >= 'A' && sentence[i + 1] <= 'Z') {
                sentence[i + 1] += 32;
            }
            if (sentence[i - 1] != sentence[i + 1]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    string sentence = "leetcodE ec cool";
    if (isCircularSentence(sentence)) {
        cout << "Circular";
    }
    else {
        cout << "Not Circular";
    }
}