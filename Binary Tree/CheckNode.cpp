// Program to check whether a given node is present in the binary tree or not
#include "BinaryTreeNode.h"
bool checkNode(BinaryTreeNode<int>* root, int key) {
    if(root == NULL) return false;
    if(root->data == key) return true;
    bool flag = false;
    flag = checkNode(root->left, key) || checkNode(root->right, key);
    return flag;
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    int key;
    cin >> key;
    if(checkNode(root, key)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    delete root;
    return 0;
}