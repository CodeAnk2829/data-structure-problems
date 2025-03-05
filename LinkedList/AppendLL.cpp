// Program to Append the last n nodes of the linked list
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        next = nullptr;
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
ListNode *append(ListNode *head, int n) {
    ListNode *temp = head;
    ListNode *tail = NULL;
    int N = 0;
    while(temp != NULL) {
        if(temp->next == NULL) {
            tail = temp;
        }
        temp = temp->next;
        N++;
    }
    temp = head;
    if(N > n) {
        int i = 0;
        while(i < N - n - 1) {
            temp = temp->next;
            i++;
        }
        ListNode *a = temp->next;
        tail->next = head;
        temp->next = NULL;
        head = a;
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
        int n;
        cin >> n;
        head = append(head, n);
        print(head);
    }
    return 0;
}