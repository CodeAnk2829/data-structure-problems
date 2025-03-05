// Program to count the no. of nodes in a given binary tree
#include "BinaryTreeNode.h"
int countNodes(BinaryTreeNode<int>* root) {
    if(root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << countNodes(root) << endl;
    delete root;
    return 0;
}
