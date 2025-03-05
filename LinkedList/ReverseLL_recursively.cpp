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
ListNode *head = NULL;
void insert(int val) {
    ListNode *n = new ListNode(val);
    if(head == NULL) {
        head = n;
    } else {
        ListNode *temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
    }
}
void print(ListNode *head) {
    ListNode *temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void reverse(ListNode *p) {
    if(p == NULL) return;
    if(p->next == NULL) {
        head = p;
        return;
    }
    reverse(p->next);
    p->next->next = p;
    p->next = NULL;
}
int main() {
    insert(5);
    insert(3);
    insert(4);
    insert(6);
    print(head);
    reverse(head);
    print(head);
    return 0;
}