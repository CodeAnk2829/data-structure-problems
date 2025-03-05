#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this -> data = data;
        next = NULL;
    }
};

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *input() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;

    while(data != -1) {
        Node *node = new Node(data);
        if(head == NULL) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}

int main() {
    Node n1(1);
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(5);

    Node *head = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    print(head);
    print(head);

    Node *head2 = input();
    print(head2);

    return 0;
}