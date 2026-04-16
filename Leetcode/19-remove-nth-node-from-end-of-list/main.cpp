#include <iostream>

#include "../common/list_node.h"

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == NULL) return NULL;

    ListNode* prevNode = NULL;
    ListNode* trackerNode = head;
    ListNode* iteratorNode = head;

    for (int i = 0; i < n - 1; i++) {
        iteratorNode = iteratorNode->next;
    }

    while (iteratorNode && iteratorNode->next) {
        prevNode = trackerNode;
        trackerNode = trackerNode->next;
        iteratorNode = iteratorNode->next;
    }

    if (prevNode)
        prevNode->next = trackerNode->next;
    else
        head = head->next;
    
    return head;
}

int main() {
    ListNode* head = new ListNode(5, NULL);
    head = new ListNode(4, head);
    // head = new ListNode(3, head);
    // head = new ListNode(2, head);
    // head = new ListNode(1, head);

    ListNode* temp = removeNthFromEnd(head, 2);
    while (temp) {
        std::cout << temp->val << ' ';
        temp = temp->next;
    }
}