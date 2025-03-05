// Program for preorder traversal (meaning :- Root says print me first then my children)
#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;
TreeNode<int>* takeInput() {
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
void preorder(TreeNode<int>* root) {
    if(root == NULL) return;
    cout << root->data << endl;
    for(int i = 0; i < root->children.size(); ++i) {
        preorder(root->children[i]);
    }
} 
int main() {
    TreeNode<int> *root = takeInput();
    preorder(root);
    delete root;
    return 0;
}