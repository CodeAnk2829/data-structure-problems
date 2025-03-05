#include <bits/stdc++.h>
#include "ioformat.cpp"
using namespace std;

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *head = NULL;
    ListNode *tail = NULL;
    while (list1 != NULL && list2 != NULL) {
        if(head == NULL) {
            head = tail = (list1->data <= list2->data) ? list1 : list2;
        } else {
            tail->next = (list1->data <= list2->data) ? list1 : list2;
            tail = tail->next;
        }
        if(list1->data <= list2->data) {
            list1 = list1->next;
        } else {
            list2 = list2->next;
        }
    }
    if (tail != NULL)
        tail->next = list1 != NULL ? list1 : list2;
    else
        head = list1 != NULL ? list1 : list2;
    return head;
}

int main() {
    ListNode *head1 = NULL;
    ListNode *head2 = NULL;
    head1 = input();
    head2 = input();
    print(head1);
    print(head2);
    ListNode *head = NULL;
    head = mergeTwoLists(head1, head2);
    print(head);
    return 0;
}