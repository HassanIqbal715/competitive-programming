#include <iostream>

#include "../common/list_node.h"

ListNode* reverseList(ListNode* head) {
    if (head == nullptr) return head;
    ListNode* prev = head;
    ListNode* curr = prev->next;
    if (curr == nullptr) {
        return prev;
    }
    ListNode* next = curr->next;
    prev->next = nullptr;

    while (next != nullptr) {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = next->next;
    }
    curr->next = prev;

    return curr;
}

int main() {
    ListNode *head = new ListNode(5, nullptr);
    // head = new ListNode(4, head);
    // head = new ListNode(3, head);
    // head = new ListNode(2, head);
    // head = new ListNode(1, head);
    head = reverseList(head);

    ListNode *temp = nullptr;
    while (head != nullptr) {
        std::cout << head->val << " ";
        temp = head;
        head = head->next;
        delete temp;
    }
    std::cout << '\n';
}