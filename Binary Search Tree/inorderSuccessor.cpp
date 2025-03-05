#include "BinaryTreeNode.h"
pair<int, int> solve(BinaryTreeNode<int>* root, int key) {
    int successor = -1;
    int predecessor = -1;
    while(root != NULL) {
        if(root->data < key) {
            predecessor = root->data;
            root = root->right;
        } else if(root->data > key) {
            successor = root->data;
            root = root->left;
        } else {
            BinaryTreeNode<int> *temp = root->left;
            while(temp->right != NULL) {
                temp = temp->right;
            }
            predecessor = temp->data;

            temp = root->right;
            while(temp->left != NULL) {
                temp = temp->left;
            }
            successor = temp->data;
            root = root->right;
        }
    }
    return {predecessor, successor};
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        BinaryTreeNode<int> *root = takeInput();
        int key;
        cin >> key;
        // printTree(root);
        // cout << key << endl;
        pair<int, int> p = solve(root, key);
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}