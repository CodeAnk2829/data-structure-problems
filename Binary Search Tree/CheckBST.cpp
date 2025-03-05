// Program to check whether a given binary tree is BST or not. 
// Time Complexity = O(n*logn) in case when balanced BST
// Time Complexity = O(n*n) in case when right oriented tree or left oriented tree
// Hence time complexity depends on the hright of the binary tree --> TC = O(n * h)
// This should be more efficient--> checkBST2
#include "BinaryTreeNode.h"
int maxElement(BinaryTreeNode<int>* root) {
    if(root == NULL) return INT_MIN;
    int leftMax = maxElement(root->left);
    int rightMax = maxElement(root->right);
    return max(root->data, max(leftMax, rightMax));
}
int minElement(BinaryTreeNode<int>* root) {
    if(root == NULL) return INT_MAX;
    int leftMin = minElement(root->left);
    int rightMin = minElement(root->right);
    return min(root->data, min(leftMin, rightMin));
}
bool isBST(BinaryTreeNode<int>* root) {
    if(root == NULL) return true;
    int leftMax = maxElement(root->left);
    int rightMin = minElement(root->right);
    bool output = (root->data > leftMax) && (root->data <= rightMin) && isBST(root->left) && isBST(root->right);
    return output;
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << isBST(root) << endl;
    return 0;
}