// Traversals in a binary tree
#include <bits/stdc++.h>
using namespace std;
class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

BinaryTreeNode *takeInput()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
        return NULL;
    BinaryTreeNode *root = new BinaryTreeNode(rootData);
    queue<BinaryTreeNode *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode *front = pendingNodes.front();
        pendingNodes.pop();
        int leftChild;
        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode *child = new BinaryTreeNode(leftChild);
            front->left = child;
            pendingNodes.push(child);
        }
        int rightChild;
        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode *child = new BinaryTreeNode(rightChild);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

void inorderTraverasal(BinaryTreeNode *root)
{
    if (root == NULL)
        return;
    inorderTraverasal(root->left);
    cout << root->data << " ";
    inorderTraverasal(root->right);
}

void preorderTraversal(BinaryTreeNode *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(BinaryTreeNode *root)
{
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    BinaryTreeNode* root = takeInput();
    cout << "Pre-Order Traversal" << endl;
    preorderTraversal(root);
    cout << endl;
    cout << "Post-Order Traversal" << endl;
    postorderTraversal(root);
    cout << endl;
    cout << "In-Order Traversal" << endl;
    inorderTraverasal(root);
    return 0;
}