// Program to search an element in a given Binary Search Tree
#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;
bool searchElement(BinaryTreeNode<int>* root, int key) {
    if(!root) return false;
    if(root->data == key) {
        return true;
    } else if(root->data < key) {
        return searchElement(root->right, key);
    } else {
        return searchElement(root->left, key);
    }
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int key;
    cin >> key;
    printTree(root);
    if(searchElement(root, key)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}