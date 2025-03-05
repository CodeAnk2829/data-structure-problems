#include <iostream>
using namespace std;
class node
{
public: 
    int data;
    node* next; 
    node(int data) {
        this -> data = data;
        next = NULL;
    }
    friend ostream &operator<<(ostream &, node *);
};
ostream &operator<<(ostream &o, node *head) {
    while(head != NULL) {
        cout << head -> data << " ";
        head = head -> next;
    }
    return o;
}
node* input() {
    int data;
    cin >> data;
    node *head = NULL;
    node *tail = NULL;
    while(data != -1) {
        node *n = new node(data);
        if(head == NULL) {
            head = tail = n;
        } else {
            tail -> next = n;
            tail = tail -> next;
        }
        cin >> data;
    }
    return head;
}
int main() {
/*
    // Statically
    node n1(4);
    node *head1 = &n1;
    node n2(5);
    n1.next = &n2;
    cout << head1 << endl;

    // Dynamically
    node *n3 = new node(10);
    node *n4 = new node(30);
    node *head2 = n3;
    n3 -> next = n4;
    cout << head2 << endl;
*/

    node *head = input();
    cout << head << endl;
    return 0;
}