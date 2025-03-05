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
ListNode *remove_duplicate(ListNode *head) {
    ListNode *curr = head;
    ListNode *temp = curr->next;
    while(temp != NULL) {
        while(curr->val == temp->val) {
            ListNode *a = temp;
            curr->next = temp = temp->next;
            delete(a);
        }
        curr = curr->next;
        temp = temp->next;
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
int main() {
    int t;
    cin >> t;
    while(t--) {
        ListNode *head = NULL;
        head = input();
        head = remove_duplicate(head);
        print(head);
    }

    return 0;
}
