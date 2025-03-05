#include <iostream>
using namespace std;
class ListNode
{
public: 
    int val;
    ListNode *next;

    ListNode(int data) {
        val = data;
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
        }
        else {
            tail->next = newNode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}

void print(ListNode *head) {
    while(head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode *Delete(ListNode *head, int pos) {
    int count = 0;
    ListNode *temp = head;
    while(count < pos - 1) {
        temp = temp->next;
        count++;
    }
    if(temp->next == NULL) {
        return (pos == 0) ? NULL : head;
    } else {
        if(pos == 0) {
            head = head->next;
            delete(temp);
        } else {
            ListNode *a = temp->next;
            ListNode *b = a->next;
            temp->next = b;
            delete (a);
        }
    }
    return head;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        ListNode *head = NULL;
        head = input();
        int pos;
        cin >> pos;
        head = Delete(head, pos);
        print(head);
    }
    return 0;
}