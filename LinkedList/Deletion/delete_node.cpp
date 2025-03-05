#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};


Node *convertArrToLL(vector<int>& arr) {
    Node *head = new Node(arr[0]);
    Node *tail = head;
    for(int i = 1; i < arr.size(); ++i) {
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* removeHead(Node *head) {
    if(head == NULL) return NULL;
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node *removeTail(Node *head) {
    cout << head << endl;
    if(head == NULL || head->next == NULL) {
        return NULL;
    }
    Node *temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
    return head;
}

int main() {
    vector<int> arr = {12, 3, 2, 4, 6, 7, 8};

    Node *head = convertArrToLL(arr);
    print(head);
    cout << head << endl;
    // Delete head node
    Node *withoutHead = removeHead(head);
    print(withoutHead);
    cout << head << endl;
    // Delete tail node
    Node *withoutTail = removeTail(head);
    print(withoutTail);
    cout << head << endl;

    return 0;
}