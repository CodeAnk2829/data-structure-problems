// Program to find the node N in the given linked list
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        next = NULL;
    }
};
ListNode *input() {
    int data;
    cin >> data;
    ListNode *head = NULL;
    ListNode *tail = NULL;
    while(data != -1) {
        ListNode *n = new ListNode(data);
        if(head == NULL) {
            head = tail = n;
        } else {
            tail->next = n;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}
int find(ListNode *head, int n) {
    ListNode *temp = head;
    int index = 0;
    while (temp != NULL) {
        if(temp->val == n) return index;
        temp = temp->next;
        index++;
    }
    return -1;
}
int main() {
    int t;
    cin >> t;
    while(t--) {

    ListNode *head = NULL;
    head = input();
    int n;
    cin >> n;
    cout << find(head, n) << endl;
    }
    return 0;
}