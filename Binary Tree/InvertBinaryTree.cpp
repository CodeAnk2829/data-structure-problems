// Problem - To invert the binary tree
#include "BinaryTreeNode.h"
BinaryTreeNode<int> *invertTree(BinaryTreeNode<int> *root){
    if (!root)
        return NULL;
    BinaryTreeNode<int> *leftChild = invertTree(root->left);
    BinaryTreeNode<int> *rightChild = invertTree(root->right);
    root->left = rightChild;
    root->right = leftChild;
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    BinaryTreeNode<int>* invertedBinaryTree = invertTree(root);
    printBinaryTree(invertedBinaryTree);
    return 0;
}