// Program to print nodes at level or depth k
#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;
void printNodeAtlevelK(TreeNode<int> *root , int k) {
    if(root == NULL) return;
    if(k == 0) {
        cout << root->data << " ";
    }
    for(int i = 0; i < root->children.size(); ++i) {
        printNodeAtlevelK(root->children[i], k - 1);
    }
}
TreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int> (rootData);
    queue<TreeNode<int>*> queuenodes;
    queuenodes.push(root);
    while(queuenodes.empty() != true) {
        TreeNode<int>* front = queuenodes.front();
        queuenodes.pop();
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i) {
            int numChild;
            cin >> numChild;
            TreeNode<int> *child = new TreeNode<int> (numChild);
            front->children.push_back(child);
            queuenodes.push(child);
        }
    }
    return root;
}
void printTree(TreeNode<int> *root) {
    if(root == NULL) return;
    queue<TreeNode<int>*> queuenodes;
    queuenodes.push(root);
    while(queuenodes.empty() != true) {
        TreeNode<int> *front = queuenodes.front();
        cout << front->data << " : ";
        queuenodes.pop();
        for(auto &i : front->children) {
            cout << i->data << " ";
            queuenodes.push(i);
        }
        cout << endl;
    }
}
int main() {
    TreeNode<int>* root = takeInput();
    printTree(root);
    printNodeAtlevelK(root, 2);
    delete root;
    return 0;
}