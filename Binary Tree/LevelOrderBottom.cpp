// Problem - To do the level order traversal from the bottom
#include "BinaryTreeNode.h"
vector<vector<int>> levelOrderBottom(BinaryTreeNode<int>* root) {
    vector<vector<int>> ans;
    stack<vector<int>> s;
    if(!root) return ans;
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()) {
        vector<int> level;
        int size = pendingNodes.size();
        for(int i = 0; i < size; ++i) {
            BinaryTreeNode<int>* currentNode = pendingNodes.front();
            pendingNodes.pop();
            if(currentNode->left != NULL) {
                pendingNodes.push(currentNode->left);
            }
            if(currentNode->right != NULL) {
                pendingNodes.push(currentNode->right);
            }
            level.push_back(currentNode->data);
        }
        s.push(level);
    }
    while(!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();

    vector<vector<int>> v = levelOrderBottom(root);
    for(int i = 0; i < v.size(); ++i) {
        for(auto &p : v[i]) {
            cout << p << " ";
        }
        cout << endl;
    }

    return 0;
}