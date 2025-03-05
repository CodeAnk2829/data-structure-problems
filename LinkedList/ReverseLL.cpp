#include <iostream>
using namespace std;
class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode(int data) {
        this->data = data;
        next = NULL;
    }
};
ListNode *insert(ListNode *head, int val) {
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
    return head;
}
ListNode *reverse(ListNode *head) {
    ListNode *curr = head;
    ListNode *prev = NULL;
    ListNode *temp = NULL; 
    while(curr != NULL) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp; 
    }
    head = prev;
    return head;
}


void print(ListNode *head) {
    ListNode *temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    ListNode *head = NULL;
    ListNode *n = new ListNode(5);
    head = n;
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);
    head = insert(head, 4);
    print(head);
    head = reverse(head);
    print(head);
    return 0;
}