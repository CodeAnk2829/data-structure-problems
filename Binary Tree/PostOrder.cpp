// Function to do postorder traversal in a binary tree
#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;
void postorder(BinaryTreeNode<int>* root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data <<  " ";
}