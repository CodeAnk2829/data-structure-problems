// Program to build actual tree by using postorder and inorder traversal
#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;
BinaryTreeNode<int>* buildTreeHelper(int* post, int *in, int postS, int postE, int inS, int inE) {
    if(inS > inE) return NULL;
    int rootData = post[postE];
    BinaryTreeNode<int>* root = new BinaryTreeNode<int> (rootData);
    int rootIndex = -1;
    for(int i = inS; i <= inE; ++i) {
        if(rootData == in[i]) {
            rootIndex = i;
            break;
        }
    }
    int linS = inS;
    int linE = rootIndex - 1;
    int lpostS = postS;
    int lpostE = linE - linS + lpostS;
    int rinS = rootIndex + 1;
    int rinE = inE;
    int rpostS = lpostE + 1;
    int rpostE = postE - 1;
    root->left = buildTreeHelper(post, in, lpostS, lpostE, linS, linE);
    root->right = buildTreeHelper(post, in, rpostS, rpostE, rinS, rinE);
}
BinaryTreeNode<int>* buildTree(int *post, int *in, int size) {
    return buildTreeHelper(post, in, 0, size - 1, 0, size - 1);
}
void printTree(BinaryTreeNode<int>* root) {
    if(root == NULL) return;
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0) {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << " : L:";
        if(front->left != NULL) {
            cout << front->left->data << " ";
            pendingNodes.push(front->left);
        } else {
            cout << -1 << " ";
        }
        cout << "R:";
        if(front->right != NULL) {
            cout << front->right->data;
            pendingNodes.push(front->right);
        } else {
            cout << -1;
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    int post[n];
    for (int i = 0; i < n; ++i)
        cin >> post[i];
    int in[n];
    for (int i = 0; i < n; ++i)
        cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(post, in, n);
    printTree(root);
    delete root;
    return 0;
}