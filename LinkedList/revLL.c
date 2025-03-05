#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int data;
    struct ListNode *next;
};
struct ListNode *head = NULL;
void reverse() {
    struct ListNode *curr = head;
    struct ListNode *prev = NULL;
    struct ListNode *next = NULL;
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}
void input() {
    int val;
    struct ListNode *tail = NULL;
    scanf("%d", &val);
    while(val != -1) {
        struct ListNode *n = (struct ListNode *)malloc(sizeof(int));
        n->data = val;
        n->next = NULL;
        if(head == NULL) {
            head = tail = n;
        } else {
            tail->next = n;
            tail = tail->next;
        }
        scanf("%d", &val);
    }
}
void print() {
    struct ListNode *temp =  head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    input();
    print();
    reverse();
    print();
    return 0;
}