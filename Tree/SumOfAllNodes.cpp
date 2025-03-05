// Program to calculate the sum of all nodes present in the tree
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
    while(q.empty() != true) {
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
int sumNodes(TreeNode <int>* root) {
    if(root == NULL) return 0;
    if(root->children.size() == 0) return root->data;
    int sum = root->data; 
    for(int i = 0; i < root->children.size(); ++i) {
        sum += sumNodes(root->children[i]);
    }
    return sum;
}
int main() {
    TreeNode <int>* root = takeInput();
    printTree(root);
    cout << sumNodes(root) << endl;
    delete root;
    return 0;
}