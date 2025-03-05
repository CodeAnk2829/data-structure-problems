#include "ioformat.cpp"
ListNode* merge(ListNode* list1, ListNode* list2) {
    ListNode* head = NULL;
    ListNode* tail = NULL;
    while(list1 != NULL && list2 != NULL) {
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
    if(tail != NULL) {
        tail->next = (list1 != NULL) ? list1 : list2;
    } else {
        head = (list1 != NULL) ? list1 : list2;
    }
    return head;
}
ListNode* midNode(ListNode* head) { 
    if(head == NULL) return NULL;
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode* mergeSort(ListNode* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    ListNode* mid = midNode(head);
    ListNode* temp = mid->next;
    mid->next = NULL;
    ListNode* l1 = mergeSort(head);
    ListNode* l2 = mergeSort(temp);
    head = merge(l1, l2);
    return head;
}
ListNode* reverseLL(ListNode* head) {
    if(!head) return NULL;
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* temp = NULL;
    while(curr != NULL) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
    return head;
}
ListNode* reverseLinkedList(ListNode* head) {
    if(!head) return;
    ListNode* temp;
    if(!head->next) {
        temp = head;
        return temp;
    }
    temp = reverseLinkedList(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}
int main() {
    ListNode* head = input();
    head = mergeSort(head);
    print(head);
    return 0;
}