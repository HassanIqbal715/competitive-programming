#include <unordered_set>
#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> arr) {
    int i=0;
    for(int j=1; j < arr.size(); j++){
        if(arr[i]!=arr[j]){
            i++;
            arr[i]=arr[j];
        }
    }
    return i+1;
}

int main() {
    cout << removeDuplicates({1, 1, 2}) << '\n';
}
