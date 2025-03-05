// Program to print nodes according to postorder traversal (meaning :- Root says first print my children then come to me)
#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;
TreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int> (rootData);
    queue<TreeNode<int>*> queuenodes;
    queuenodes.push(root);
    while(queuenodes.empty() != true) {
        TreeNode<int> *front = queuenodes.front();
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
void postorder(TreeNode<int> *root) {
    if(root == NULL) return;
    for(int i = 0; i < root->children.size(); ++i) {
        postorder(root->children[i]);
    }
    cout << root->data << endl;
}
int main() {
    TreeNode<int> *root = takeInput();
    postorder(root);
    delete root;
    return 0;
}