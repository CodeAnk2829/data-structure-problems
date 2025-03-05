// Program to find the largest node in the given tree
#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;
TreeNode <int>* takeInput() {
    int rootData;
    cin >> rootData;
    TreeNode <int>* root = new TreeNode <int>(rootData);
    queue <TreeNode <int>*> queueNode;
    queueNode.push(root);
    while(queueNode.size() != 0) {
        TreeNode <int>* front = queueNode.front();
        queueNode.pop();
        int numChild;
        cin >> numChild;
        for(int i = 0; i < numChild; ++i) {
            int n;
            cin >> n;
            TreeNode <int>* child = new TreeNode <int>(n);
            front->children.push_back(child);
            queueNode.push(child);
        }
    }
    return root;
}
void printTree(TreeNode <int>* root) {
    if(root == NULL) return;
    queue <TreeNode <int>*> q;
    q.push(root);
    while(q.size() != 0) {
        TreeNode <int>* front = q.front();
        cout << front->data << " : ";
        q.pop();
        for(int i = 0; i < front->children.size(); ++i) {
            cout << front->children[i]->data << " ";
            q.push(front->children[i]);
        }
        cout << endl;
    }
}
TreeNode <int>* LargestNode(TreeNode <int>* root) {
    if(root == NULL) return root;
    TreeNode <int>* max = new TreeNode <int>(root->data);
    for(int i = 0; i < root->children.size(); ++i) {
        TreeNode <int>* temp = LargestNode(root->children[i]);
        if(max->data < temp->data) {
            max = temp;
        }
    }
    return max;
}
int main() {
    TreeNode <int>* root = NULL;
    root = takeInput();
    printTree(root);
    TreeNode <int>* ans = LargestNode(root);
    cout << ans->data;
    delete root;
    return 0;
}