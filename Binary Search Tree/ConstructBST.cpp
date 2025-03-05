#include "BinaryTreeNode.h"
BinaryTreeNode<int>* constructBST(vector<int>& v, int low, int high) {
    if(low > high) {
        return NULL;
    }
    int mid = (low + high) / 2;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int> (v[mid]);
    root->left = constructBST(v, low, mid - 1);
    root->right = constructBST(v, mid + 1, high);

    return root;
}