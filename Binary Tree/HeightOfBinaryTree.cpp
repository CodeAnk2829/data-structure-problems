#include "BinaryTreeNode.h"
using namespace std;
int heightOfBinaryTree(BinaryTreeNode<int>* root) {
    if(root == NULL) return 0;
    int h = 0;
    int left_height = heightOfBinaryTree(root->left);
    int right_height = heightOfBinaryTree(root->right);
    return 1 + max(left_height, right_height);
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << heightOfBinaryTree(root) << endl;
    delete root;
    return 0;
}