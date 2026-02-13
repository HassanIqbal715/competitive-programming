#include <iostream>
#include <climits>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* next;
};

class MinStack {
private:
    Node* head;
    vector<int> minHistory;

public:
    MinStack() {
        head = nullptr;
    }
    
    void push(int val) {
        Node* newNode = new Node;
        newNode->val = val;
        newNode->next = head;
        head = newNode;
        if (minHistory.size() >= 1) {
            minHistory.push_back(min(minHistory.back(), val));
            return;
        }
        minHistory.push_back(val);
    }
    
    void pop() {
        if (head == nullptr) return;
        Node* currentNode = head;
        head = head->next;
        minHistory.pop_back();
        delete currentNode;
    }
    
    int top() {
        if (head == nullptr) return 0;
        return head->val;
    }
    
    int getMin() {
        if (head == nullptr) return 0;
        return minHistory.back();
    }
};

int main() {
    MinStack stk;
    stk.push(-2);
    stk.push(0);
    stk.push(-3);
    cout << stk.getMin() << endl;
    stk.pop();
    cout << stk.top() << endl;
    cout << stk.getMin() << endl;
}