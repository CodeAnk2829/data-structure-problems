#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;
void printInRange(BinaryTreeNode<int> *root, int k1, int k2) {
    if (!root) return;
    if (root->data < k1) {
        printInRange(root->right, k1, k2);
    }
    else if (root->data > k2) {
        printInRange(root->left, k1, k2);
    }
    else {
        printInRange(root->left, k1, k2);
        cout << root->data << " ";
        printInRange(root->right, k1, k2);
    }
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    int k1, k2;
    cin >> k1 >> k2;
    printInRange(root, k1, k2);
    return 0;
}