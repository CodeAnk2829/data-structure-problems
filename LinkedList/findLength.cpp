// Program to find the length of a linked list (recursively).
#include <iostream>
using namespace std;
struct ListNode
{
    int data;
    ListNode *next;

    ListNode(int data) {
        this->data = data;
        next = NULL;
    }
};
ListNode *input() {
    int val;
    cin >> val;
    ListNode *head = NULL;
    ListNode *tail = NULL;
    while(val != -1) {
        ListNode *n = new ListNode(val);
        if(head == NULL) {
            head = tail = n;
        } else {
            tail->next = n;
            tail = tail->next;
        }
        cin >> val;
    }
    return head;
}
int find_length(ListNode *head) {
    if(head == NULL) return 0;
    if(head->next == NULL) return 1;
    int count = 1 + find_length(head->next);
    return count;
}
int main() {
    ListNode *head = NULL;
    head = input();
    cout << find_length(head);
    return 0;
}