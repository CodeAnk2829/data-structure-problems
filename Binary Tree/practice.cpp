#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;
// BinaryTreeNode<int>* takeInput() {
//     int rootData;
//     cin >> rootData;
//     if(rootData == -1) return NULL;
//     BinaryTreeNode<int>* root = new BinaryTreeNode<int> (rootData);
//     queue<BinaryTreeNode<int>*> pendingNodes;
//     pendingNodes.push(root);
//     while(pendingNodes.size() != 0) {
//         BinaryTreeNode<int>* front = pendingNodes.front();
//         pendingNodes.pop();
//         int leftChild;
//         cin >> leftChild;
//         if(leftChild != -1) {
//             BinaryTreeNode<int>* child = new BinaryTreeNode<int> (leftChild);
//             front->left = child;
//             pendingNodes.push(child);
//         } 
//         int rightChild;
//         cin >> rightChild;
//         if(rightChild != -1) {
//             BinaryTreeNode<int>* child = new BinaryTreeNode<int> (rightChild);
//             front->right = child;
//             pendingNodes.push(child);
//         }
//     }
//     return root;
// }
// void printTree(BinaryTreeNode<int>* root) {
//     if(root == NULL) return;
//     queue<BinaryTreeNode<int>*> pendingNodes;
//     pendingNodes.push(root);
//     while(pendingNodes.size() != 0) {
//         BinaryTreeNode<int>* front = pendingNodes.front();
//         pendingNodes.pop();
//         cout << front->data << " : L:";
//         if(front->left != NULL) {
//             cout << front->left->data << " ";
//             pendingNodes.push(front->left);
//         } else {
//             cout << -1 << " ";
//         }
//         cout << "R:";
//         if(front->right != NULL) {
//             cout << front->right->data;
//             pendingNodes.push(front->right);
//         } else {
//             cout << -1;
//         }
//         cout << endl;
//     }
// }
int countNodes(BinaryTreeNode<int>* root) {
    if(root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
bool isNodePresent(BinaryTreeNode<int>* root, int key) {
    if(root == NULL) return false;
    if(root->data == key) return true;
    return isNodePresent(root->left, key) || isNodePresent(root->right, key);
}
int height(BinaryTreeNode<int>* root) {
    if (root == NULL) return 0;
    return 1 + max(height(root->left), height(root->right));
}
void MirrorTree(BinaryTreeNode<int>* root) {
    if(root == NULL) return;
    cout << root->data << endl;
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0) {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        if(front->right != NULL) {
            cout << front->right->data << " ";
            pendingNodes.push(front->right);
        }
        if(front->left != NULL) {
            cout << front->left->data << " ";
            pendingNodes.push(front->left);
        }
        cout << endl;
    }
}
void preorder(BinaryTreeNode<int>* root) {
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(BinaryTreeNode<int>* root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void inorder(BinaryTreeNode<int>* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void levelOrderTraversal(BinaryTreeNode<int>* root) {
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()) {
        int size = pendingNodes.size();
        for(int i = 0; i < size; ++i) {
            BinaryTreeNode<int>* front = pendingNodes.front();
            pendingNodes.pop();
            if(front->left != NULL) {
                pendingNodes.push(front->left);
            }
            if(front->right != NULL) {
                pendingNodes.push(front->right);
            } 
            cout << front->data << " ";
        }
        cout << endl;
    }
}
pair<int, int> heightDiameter(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        pair<int, int> p;
        p.first = p.second = 0;
        return p;
    }
    pair<int, int> left = heightDiameter(root->left);
    pair<int, int> right = heightDiameter(root->right);
    int lh = left.first;
    int ld = left.second;
    int rh = right.first;
    int rd = right.second;
    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));
    pair<int, int> p;
    p.first = height;
    p.second = diameter;
    return p;
}
int sumOfNodes(BinaryTreeNode<int>* root) {
    if(!root) return 0;
    return root->data + sumOfNodes(root->left) + sumOfNodes(root->right);
}
bool isBalanced(BinaryTreeNode<int>* root) {
    if(!root) return true;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int diff = max(leftHeight, rightHeight) - min(leftHeight, rightHeight);
    if(diff <= 1) return true;
    return false;
}
int main() {
    // BinaryTreeNode<int>* root = takeInput();
    // printTree(root);
    /*int k;
    cin >> k;
    cout << countNodes(root) << endl;
    if(isNodePresent(root, k)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    cout << height(root) << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    inorder(root);
    cout << endl;*/
    // levelOrderTraversal(root);
    // cout << sumOfNodes(root) << endl;
    // if(isBalanced(root)) {
    //     cout << "true" << endl;
    // } else {
    //     cout << "false" << endl;
    // }
    // delete root;

    cout << __gcd(15432525245, 10000000000);
    return 0;
}