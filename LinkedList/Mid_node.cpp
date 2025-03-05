// Program to find the middle node of a linked list.
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
int mid_list(ListNode *head) {
    ListNode *temp = head;
    int len = 0;
    while(temp != NULL) {
        len++;
        temp = temp->next;
    }
    int mid = (len - 1) / 2;
    temp = head;
    int i = 0;
    while(i < mid) {
        temp = temp->next;
        i++;
    }
    return temp->data;
}

int find_mid(ListNode *head) {
    if(head == NULL) {
        return 0;
    }
    ListNode *slow = head;
    ListNode *fast = head->next;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}
ListNode *clear(ListNode *head) {
    while(head != NULL) {
        ListNode *temp = head;
        head = head->next;
        delete(temp);
    }
    return head;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        ListNode *head = NULL;
        head = input();

        // Find middle of the list wihtout knowing the length of the list
        cout << find_mid(head) << endl;

        // Find middle of the list by using length of the list
        cout << mid_list(head) << endl;

        // Clear function to clear the list
        head = clear(head); 
    }
    return 0;
}