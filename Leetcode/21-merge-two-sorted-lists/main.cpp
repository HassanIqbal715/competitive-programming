#include <iostream>

#include "../common/list_node.h"

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;

    ListNode newList(0, nullptr);
    ListNode *result = &newList;

    while (list1 && list2) {
        ListNode* temp;
        if (list1->val < list2->val) {
            result->next = list1;
            list1 = list1->next;
            result = result->next;
        }
        else {
            result->next = list2;
            list2 = list2->next;
            result = result->next;
        }
    }

    if (list1)
        result->next = list1;
    
    if (list2)
        result->next = list2;

    return newList.next;
}

int main() {
    ListNode* list1 = new ListNode(4, nullptr);
    list1 = new ListNode(2, list1);
    list1 = new ListNode(1, list1);

    ListNode* list2 = new ListNode(4, nullptr);
    list2 = new ListNode(3, list2);
    list2 = new ListNode(1, list2);

    ListNode* cleanerNode = nullptr;    
    ListNode *sortedList = mergeTwoLists(list1, list2);

    while (sortedList) {
        std::cout << sortedList->val << " ";
        cleanerNode = sortedList;
        sortedList = sortedList->next;
        delete cleanerNode;
    }
}