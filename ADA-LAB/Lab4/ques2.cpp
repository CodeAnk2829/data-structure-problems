// C++ implementation to merge k
// sorted linked lists
// Using MIN HEAP method

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

// Utility function to create
// a new node
struct Node *newNode(int data)
{
    // Allocate node
    struct Node *new_node = new Node();

    // Put in the data
    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

// 'compare' function used to build
// up the priority queue
struct compare
{
    bool operator()(
        struct Node *a, struct Node *b)
    {
        return a->data > b->data;
    }
};

// Function to merge k sorted linked lists
struct Node *mergeKSortedLists(
    struct Node *arr[], int K)
{
    // Priority_queue 'pq' implemented
    // as min heap with the help of
    // 'compare' function
    priority_queue<Node *, vector<Node *>, compare> pq;

    // Push the head nodes of all
    // the k lists in 'pq'
    for (int i = 0; i < K; i++)
        if (arr[i] != NULL)
            pq.push(arr[i]);

    // Handles the case when k = 0
    // or lists have no elements in them
    if (pq.empty())
        return NULL;

    struct Node *dummy = newNode(0);
    struct Node *last = dummy;

    // Loop till 'pq' is not empty
    while (!pq.empty())
    {
        // Get the top element of 'pq'
        struct Node *curr = pq.top();
        pq.pop();

        // Add the top element of 'pq'
        // to the resultant merged list
        last->next = curr;
        last = last->next;

        // Check if there is a node
        // next to the 'top' node
        // in the list of which 'top'
        // node is a member
        if (curr->next != NULL)

            // Push the next node of top node
            // in 'pq'
            pq.push(curr->next);
    }

    // Address of head node of the required
    // merged list
    return dummy->next;
}

// Function to print the singly
// linked list
void printList(struct Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

// Driver code
int main()
{
    // Number of linked lists
    int N = 3;

    // Number of elements in each list
    int K = 4;

    // An array of pointers storing the
    // head nodes of the linked lists
    Node *arr[N];

    // Creating k = 3 sorted lists
    arr[0] = newNode(1);
    arr[0]->next = newNode(3);
    arr[0]->next->next = newNode(5);
    arr[0]->next->next->next = newNode(7);

    arr[1] = newNode(2);
    arr[1]->next = newNode(4);
    arr[1]->next->next = newNode(6);
    arr[1]->next->next->next = newNode(8);

    arr[2] = newNode(0);
    arr[2]->next = newNode(9);
    arr[2]->next->next = newNode(10);
    arr[2]->next->next->next = newNode(11);

    // Merge the k sorted lists
    struct Node *head = mergeKSortedLists(arr, N);

    // Print the merged list
    cout << "Now the merge list is: " << endl;
    printList(head);

    return 0;
}