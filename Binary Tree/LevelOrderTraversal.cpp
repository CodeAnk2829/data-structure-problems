#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;
vector<vector<int>> levelOrder(BinaryTreeNode<int>* root) {
    vector<vector<int>> node;
    if(!root) return node;
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()) {
        int size = pendingNodes.size();
        vector<int> level;
        for(int i = 0; i < size; ++i) {
            BinaryTreeNode<int>* front = pendingNodes.front();
            pendingNodes.pop();
            if(front->left != NULL) {
                pendingNodes.push(front->left);
            }
            if(front->right != NULL) {
                pendingNodes.push(front->right);
            }
            level.push_back(front->data);
        }
        node.push_back(level);
    }
    return node;
}