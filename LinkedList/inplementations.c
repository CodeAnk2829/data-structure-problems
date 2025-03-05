#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
struct node* head = NULL;


void insertFirst(int val) 
{
    struct node* p = (struct node*) malloc (sizeof(struct node));
    p->data = val;
    p->next = NULL;
    if(head == NULL) {
        head = p;
    } else {
        p->next = head;
        head = p;
    }
}


void insertLast(int val) 
{
    struct node* p = (struct node*) malloc (sizeof(struct node));
    p->data = val;
    p->next = NULL;
    struct node *temp = NULL;
    if(head == NULL) {
        head = p;
    } else {
        temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = p;
    }
}

void insert(int val, int pos)
{
    struct node* p = (struct node*) malloc (sizeof(struct node));
    p->data = val;
    p->next = NULL;
    struct node* temp = NULL;
    if(head == NULL) {
        head = p;
    } else {
        int count = 1;
        temp = head;
        while(count != pos) {
            temp = temp->next;
            count++;
        }
        p->next = temp->next;
        temp->next = p;
    }
}

void display()
{
    for (struct node *i = head; i != NULL; i = i->next) {
        printf("%d ", i->data);
    }
}

int main()
{
    for(int i = 0; i < 5; ++i) {
        insertFirst(i);
    }
    display();
    printf("\n");
    for(int i = 4; i < 10; ++i) {
        insertLast(i);
    }
    
    insert(435, 5);
    display();

    return 0;
}