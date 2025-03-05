#include <bits/stdc++.h>
#include "ioformat.cpp"
using namespace std;


ListNode *linkedList = NULL;


ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *head = NULL;
    ListNode *tail = NULL;
    while (list1 != NULL && list2 != NULL) {
        if (head == NULL) {
            head = tail = (list1->data <= list2->data) ? list1 : list2;
        }
        else {
            tail->next = (list1->data <= list2->data) ? list1 : list2;
            tail = tail->next;
        }
        if (list1->data <= list2->data) {
            list1 = list1->next;
        }
        else {
            list2 = list2->next;
        }
    }
    if (tail != NULL)
        tail->next = list1 != NULL ? list1 : list2;
    else
        head = list1 != NULL ? list1 : list2;
    return head;
}
ListNode *find_mid(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode *merge_sort(ListNode *head) {
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *mid = find_mid(head);
    ListNode *temp = mid->next;
    mid->next = NULL;
    ListNode *l1 = merge_sort(head);
    ListNode *l2 = merge_sort(temp);
    head = mergeTwoLists(l1, l2);
    return head;
}
int main() {
    linkedList = input();
    ListNode *temp = merge_sort(linkedList);
    print(temp);
    return 0;
}