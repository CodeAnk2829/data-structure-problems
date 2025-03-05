// Function to do inorder traversal in a binary tree
#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;
void inorder(BinaryTreeNode<int>* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}