#include "ListNode.cpp"
void print(ListNode *head)
{
    if(head == NULL) return;
    ListNode *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
ListNode* input()
{
    int data;
    cin >> data;
    ListNode *head = NULL;
    ListNode *tail = NULL;
    while (data != -1)
    {
        ListNode *n = new ListNode(data);
        if (head == NULL) {
            head = tail = n;
        }
        else {
            tail->next = n;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}
