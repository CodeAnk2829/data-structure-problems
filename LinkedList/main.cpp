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
        Node *temp = new Node(arr[i]);
        tail->next = temp;
        tail = tail->next;
    }
    return head;
}

void printLL(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(auto &i : arr) cin >> i;

    Node *head = convertArrToLL(arr);
    printLL(head);
    return 0;
}