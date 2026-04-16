#include <iostream>
#include <map>
#include <vector>

bool isNStraightHand(std::vector<int> hand, int groupSize) {
    std::map<int, int> map;
    for (int card : hand) {
        map[card]++;
    }
    
    if (hand.size() % groupSize != 0 || map.size() < groupSize) {
        return false;
    }

    int count = 0;
    int n = hand.size()/groupSize;
    std::vector<int> currentValues;

    for (int i = 0; i < hand.size()/groupSize; i++) {
        count = 0;
        currentValues.clear();
        for (auto it = map.begin(); it != map.end() && count < groupSize; it++) {
            if (it->second <= 0)
                continue;
            if (currentValues.size() == 0 || 
                currentValues.back() + 1 == it->first) {
                count++;
                it->second -= 1;
                currentValues.push_back(it->first);
            }
        }
        if (count < groupSize)
            return false;
    }
    return true;
}

int main() {
    std::cout << isNStraightHand({1, 2, 3, 4, 5}, 4) << '\n';
}