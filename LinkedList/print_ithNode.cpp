// Program to print ith element of a linked list
#include <iostream>
using namespace std;
class Node { 
public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        next = NULL;
    }
    Node *input();
};

Node* Node :: input() {
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while(data != -1) {
        Node *newNode = new Node(data);
        if(head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
        cin >> data;
    }
    return head;
}

int main() {
    int t; 
    cin >> t;
    Node *head = NULL;
    while(t--) {
       head = head->input();
       int i;
       cin >> i;
       int j = 0;
       Node *temp = head;
       while(j != i && temp->next != NULL) {
           temp = temp->next;
           j++;
       }
       cout << temp->data << endl;
    }
    return 0;
}