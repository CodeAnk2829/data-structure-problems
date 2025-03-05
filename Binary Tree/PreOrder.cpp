// Funciton to do preorder traversal in binary tree
#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;
void preorder(BinaryTreeNode<int>* root) {
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}