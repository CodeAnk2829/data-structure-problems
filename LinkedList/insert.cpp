// Program to insert a new nelement to the existing list at ith position
#include <iostream>
using namespace std;
class ListNode
{
public:
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
        ListNode *newNode = new ListNode(data);
        if(head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}
void print(ListNode *head) {
    ListNode *temp = head;
    while(temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
ListNode *insert(ListNode *head, int data, int pos) {
    ListNode *temp = head;
    ListNode *node = new ListNode(data);
    for(int i = 0; i < pos - 1; ++i) {
        temp = temp->next;
    }
    node->next = temp->next;
    temp->next = node;
    return head;
}
int main() {
    ListNode *head = NULL;
    cout << "Enter the elements and press -1 to terminate: " << endl;
    head = input();
    int data;
    cout << "Enter new element to be add: ";
    cin >> data;
    int i;
    cout << "Enter position: ";
    cin >> i;
    cout << "Before insertion: " << endl;
    print(head);
    head = insert(head, data, i); // Insert new element to the existing list
    cout << "After insertion: " << endl;
    print(head);

    return 0;
}