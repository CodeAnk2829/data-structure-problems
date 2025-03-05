#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;
TreeNode<int>* takeInputLevelWise() {
    int rootData;
    // cout << "Enter root" << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> queueNodes;
    queueNodes.push(root);
    while(queueNodes.size() != 0) {
        TreeNode<int>* front = queueNodes.front();
        int numChild;
        // cout << "Enter num of children  of root " << front->data << endl;
        cin >> numChild;
        queueNodes.pop();
        for(int i = 0; i < numChild; ++i) {
            int n;
            // cout << "Enter " << i << "th child of node " << front->data << endl;
            cin >> n;
            TreeNode<int>* child = new TreeNode<int>(n);
            front->children.push_back(child);
            queueNodes.push(child);
        }
    }
    return root;
}
void printLevelWise(TreeNode<int>* root) {
    if(root == NULL) return;
    queue<TreeNode<int>*> queueNodes;
    queueNodes.push(root);
    while(queueNodes.size() != 0) {
        TreeNode<int> *front = queueNodes.front();
        cout << front->data << " : ";
        queueNodes.pop();
        for(int i = 0; i < front->children.size(); ++i) {
            cout << front->children[i]->data << " ";
            queueNodes.push(front->children[i]);
        }
        cout << endl;
    }
}