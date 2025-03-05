#include "BinaryTreeNode.h" 
// Optimized approach--> short code than the previous one
// Top-Down approach
// TC - O(n)
bool isBSTMethod3(BinaryTreeNode<int>* root, int minima = INT_MIN, int maxima = INT_MAX) {
    if(!root) {
        return true;
    }
    if(root->data <= minima || root->data > maxima) {
        return false;
    }
    bool isLeftOk = isBSTMethod3(root->left, minima, root->data - 1);
    bool isRightOk = isBSTMethod3(root->right, root->data, maxima);

    return (isLeftOk && isRightOk);
}