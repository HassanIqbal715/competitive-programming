#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> prices) {
    int buyPrice = 0;
    int sellPrice = 0;
    int maxPrice = 0;
    int tempPrice = 0;
    int n = prices.size();

    buyPrice = prices[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        sellPrice = prices[i];
        tempPrice = buyPrice - sellPrice;
        if (tempPrice < 0) {
            buyPrice = sellPrice;
        }
        maxPrice = max(maxPrice, tempPrice);
    }

    return maxPrice;
}

int main() {
    cout << maxProfit({7, 1, 5, 3, 6, 4}) << '\n';
}
