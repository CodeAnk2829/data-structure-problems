// Program to find actual tree using inorder and preorder
#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;
void printTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << " : L:";
        if (front->left != NULL)
        {
            cout << front->left->data << " ";
            pendingNodes.push(front->left);
        }
        else
        {
            cout << -1 << " ";
        }
        cout << "R:";
        if (front->right != NULL)
        {
            cout << front->right->data;
            pendingNodes.push(front->right);
        }
        else
        {
            cout << -1;
        }
        cout << endl;
    }
}
BinaryTreeNode<int> *buildTreeHelper(int *pre, int *in, int inS, int inE, int preS, int preE)
{
    if (inS > inE)
        return NULL;
    int rootData = pre[preS];
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    int rootIndex = -1;
    for (int i = inS; i <= inE; ++i)
    {
        if (rootData == in[i])
        {
            rootIndex = i;
            break;
        }
    }
    int linS = inS;
    int linE = rootIndex - 1;
    int lpreS = preS + 1;
    int lpreE = linE - linS + lpreS;
    int rinS = rootIndex + 1;
    int rinE = inE;
    int rpreS = lpreE + 1;
    int rpreE = preE;
    root->left = buildTreeHelper(pre, in, linS, linE, lpreS, lpreE);
    root->right = buildTreeHelper(pre, in, rinS, rinE, rpreS, rpreE);
    return root;
}
BinaryTreeNode<int> *buildTree(int *pre, int *in, int size)
{
    return buildTreeHelper(pre, in, 0, size - 1, 0, size - 1);
}
int main()
{
    int n;
    cin >> n;
    int pre[n];
    for (int i = 0; i < n; ++i)
        cin >> pre[i];
    int in[n];
    for (int i = 0; i < n; ++i)
        cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(pre, in, n);
    printTree(root);
    delete root;
    return 0;
}