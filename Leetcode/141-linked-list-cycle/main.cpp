#include <iostream>

#include "../common/list_node.h"

bool hasCycle(ListNode* head) {
    ListNode *fast = head;
    ListNode *slow = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }

    return false;
}

int main() {
    ListNode *list = new ListNode(-4, nullptr);
    ListNode *temp = list;
    list = new ListNode(0, list);
    list = new ListNode(2, list);
    // temp->next = list;
    list = new ListNode(3, list);

    std::cout << hasCycle(list) << "\n";
}