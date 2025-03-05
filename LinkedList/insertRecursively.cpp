#include <bits/stdc++.h>
using namespace std;
class ListNode
{
public:
    int data;
    ListNode* next;
    ListNode(int data) {
        this->data = data;
        next = NULL;
    }
};
void print(ListNode *head)
{
    if (head == NULL)
        return;
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
ListNode *input()
{
    int val;
    cin >> val;
    ListNode *head = NULL;
    ListNode *tail = NULL;
    while (val != -1)
    {
        ListNode *n = new ListNode(val);
        if (head == NULL)
        {
            head = tail = n;
        }
        else
        {
            tail->next = n;
            tail = tail->next;
        }
        cin >> val;
    }
    return head;
}
ListNode* insert(ListNode* head, int data, int i) {
    if(!head) return NULL;
    ListNode* newNode = new ListNode(data);
    if(i == 0) {
        newNode->next = head;
        head = newNode;
        return head;
    }
    head->next = insert(head->next, data, i - 1);
    return head;
}

int main() {
    ListNode* head = input();
    print(head);
    insert(head, 99, 3);
    print(head);
    return 0;
}
