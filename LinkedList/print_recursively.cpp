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

ListNode *insert(ListNode *head, int val) {
    ListNode *n = new ListNode(val);
    if(head == NULL) {
        head = n;
    } else {
        ListNode *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
    }
    return head;
}
void print(ListNode *head) {
    if(head == NULL) {
        cout << endl;
        return ;
    }
    cout << head->data << " ";
    print(head->next);
}
void rev_print(ListNode *head) {
    if(head != NULL) {
        rev_print(head->next);
        cout << head->data << " ";
    }
}
int main() {
    ListNode *head = NULL;
    head = insert(head, 1);
    head = insert(head, 4);
    head = insert(head, 9);
    head = insert(head, 16);
    head = insert(head, 25);
    print(head); // Print the list (recursively)
    rev_print(head); // Print the list in reverse order (recursively)
    return 0;
}