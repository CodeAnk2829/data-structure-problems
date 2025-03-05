// Program to find the height of the given tree
#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;
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
            queueNode.push(child);
            front->children.push_back(child);
        }
    }
    return root;
}
int height_of_tree(TreeNode <int>* root) {
    int height = 0;
    for(int i = 0; i < root->children.size(); ++i) {
        int temp = height_of_tree(root->children[i]);
        if(height < temp) height = temp;
    }
    return height + 1;
}
int main() {
    TreeNode <int>* root = NULL;
    root = takeInput();
    printTree(root);
    cout << height_of_tree(root) << endl;
    delete root;
    return 0;
}