/*For a given Binary Tree of type integer, update it with its corresponding mirror image.*/
#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;
BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
        return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int leftChild;
        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChild);
            front->left = child;
            pendingNodes.push(child);
        }
        int rightChild;
        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChild);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}
void printMirrorImage(BinaryTreeNode<int>* root) {
    if(root == NULL) return;
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0) {
        int size = pendingNodes.size();
        for(int i = 0; i < size; ++i) {
            BinaryTreeNode<int>* front = pendingNodes.front();
            pendingNodes.pop();
            if(front->right != NULL) {
                pendingNodes.push(front->right);
            }
            if(front->left != NULL) {
                pendingNodes.push(front->left);
            } 
            cout << front->data << " ";
        }
        cout << endl;
    }
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    printMirrorImage(root);
    delete root;
    return 0;
}