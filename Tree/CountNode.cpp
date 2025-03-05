#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;
TreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    TreeNode <int>* root = new TreeNode<int> (rootData);
    queue <TreeNode <int>*> queueNodes;
    queueNodes.push(root);
    while(queueNodes.size() != 0) {
        TreeNode <int>* front = queueNodes.front();
        int numChild;
        cin >> numChild;
        queueNodes.pop();
        for(int i = 0; i < numChild; ++i) {
            int n;
            cin >> n;
            TreeNode <int>* child = new TreeNode <int>(n);
            front->children.push_back(child);
            queueNodes.push(child);
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
int countNodes(TreeNode <int>* root) {
    int ans = 1;
    for(int i = 0; i < root->children.size(); ++i) {
        ans += countNodes(root->children[i]);
    }
    return ans;
}
int main() {
    TreeNode <int>* root = NULL;
    root = takeInput();
    printTree(root);
    cout << countNodes(root) << endl;
    delete root;
    return 0;
}