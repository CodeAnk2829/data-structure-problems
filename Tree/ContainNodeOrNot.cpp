#include <iostream>
#include "TreeNode.h"
#include <queue>
using namespace std;
TreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int> (rootData);
    queue<TreeNode<int>*> queuenode;
    queuenode.push(root);
    while(queuenode.empty() != true) {
        TreeNode<int>* front = queuenode.front();
        queuenode.pop();
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i) {
            int numChild;
            cin >> numChild;
            TreeNode<int> *child = new TreeNode<int> (numChild);
            front->children.push_back(child);
            queuenode.push(child);
        }
    }
    return root;
}
bool checkNode(TreeNode<int> *root, int key) {
    if(root == NULL) return 0;
    bool flag = false;
    if(root->data == key) {
        return true;
    }
    for(int i = 0; i < root->children.size(); ++i) {
        flag = checkNode(root->children[i], key);
    }
    return flag;
}
int main() {
    TreeNode<int> *root = takeInput();
    int k;
    cin >> k;
    if(checkNode(root, k) == true) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    delete root;
    return 0;
}