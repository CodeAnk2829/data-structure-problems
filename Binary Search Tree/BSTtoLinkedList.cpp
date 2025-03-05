#include "BinaryTreeNode.h"
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
pair<ListNode*, ListNode*> BSTtoLinkedList(BinaryTreeNode<int>* root) {
    if(!root) {
        pair<ListNode*, ListNode*> p;
        p.first = p.second = NULL;
        return p;
    }
    ListNode* rootNode = new ListNode(root->data);

    pair<ListNode*, ListNode*> left = BSTtoLinkedList(root->left);
    pair<ListNode*, ListNode*> right = BSTtoLinkedList(root->right);

    ListNode* leftHead = left.first;
    ListNode* leftTail = left.second;
    ListNode* rightHead = right.first;
    ListNode* rightTail = right.second;

    if(leftTail != NULL) {
        leftTail->next =  rootNode;
    }
    rootNode->next = rightHead;
    
    pair<ListNode*, ListNode*> p;
    p.first = leftHead == NULL ? rootNode : leftHead;
    p.second = rightTail == NULL ? rootNode: rightTail;
    return p;
}

void print(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    pair<ListNode*, ListNode*> p = BSTtoLinkedList(root);
    print(p.first);
    return 0;
}