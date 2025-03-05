// Merge sort using link array
#include <iostream>
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

ListNode* takeInput() {
    int val;
    cin >> val;
    ListNode* head = NULL;
    ListNode* tail = NULL;
    while(val != -1) {
        ListNode* newNode = new ListNode(val);
        if(head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
        cin >> val;
    }
    return head;
}
void print(ListNode* head) {
    if(head == NULL) return;
    ListNode* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

ListNode* findMid(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* merge(ListNode* list1, ListNode* list2) {
    ListNode* head = NULL;
    ListNode* tail = NULL;
    while(list1 != NULL && list2 != NULL) {
        if(head == NULL) {
            head = tail = (list1->data < list2->data) ? list1 : list2;
        } else {
            tail->next = (list1->data < list2->data) ? list1 : list2;
            tail = tail->next;
        }
        if(list1->data < list2->data) {
            list1 = list1->next;
        } else {
            list2 = list2->next;
        }
    }
    if(tail != NULL) {
        tail->next = (list1 != NULL) ? list1 : list2;
    } else {
        head = (list1 != NULL) ? list1 : list2;
    }
    return head;
}

ListNode* mergeSort(ListNode* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    ListNode* mid = findMid(head);
    ListNode* temp = mid->next;
    mid->next = NULL;
    ListNode* list1 = mergeSort(head);
    ListNode* list2 = mergeSort(temp);
    head = merge(list1, list2);
    return head;
}

int main() {
    ListNode* head = takeInput();
    cout << "After sorting: " << endl;
    ListNode* ans = mergeSort(head);
    print(ans);
    return 0;
}