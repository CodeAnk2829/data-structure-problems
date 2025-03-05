#include "BinaryTreeNode.h"
class BST
{
private:
    BinaryTreeNode<int>* root;
    // Function to find the node
    bool findElement(BinaryTreeNode<int>* node, int data) {
        if(!node) return false;
        if(data == node->data) return true;
        if(data > node->data) {
            return findElement(node->right, data);
        } else {
            return findElement(node->left, data);
        }
    }
    // Function to insert a node
    BinaryTreeNode<int>* insert(BinaryTreeNode<int>* node, int data) {
        if(!node) {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int> (data);
            return newNode;
        }
        if(data < node->data) {
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }
        return node;
    }
    // Function to delete a node
    BinaryTreeNode<int>* deleteData(BinaryTreeNode<int>* node, int data) {
        if(!node) return NULL;
        if(data > node->data) {
            node->right = deleteData(node->right, data);
            return node;
        } else if(data < node->data) {
            node->left = deleteData(node->left, data);
            return node;
        } else {
            if(!node->left && !node->right) {
                delete node;
                return NULL;
            } else if(!node->left) {
                BinaryTreeNode<int>* temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            } else if(!node->right) {
                BinaryTreeNode<int>* temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            } else {
                BinaryTreeNode<int>* minNode = node->right;
                while(minNode->left != NULL) {
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = deleteData(node->right, rightMin);
                return node;
            }
        }
    }

    void printTree(BinaryTreeNode<int>* node) {
        if(!node) return;
        queue<BinaryTreeNode<int>*> pendingNodes;
        pendingNodes.push(node);
        while(!pendingNodes.empty()) {
            BinaryTreeNode<int>* front = pendingNodes.front();
            pendingNodes.pop();
            cout << front->data << " : L:";
            if(front->left != NULL) {
                cout << front->left->data << " ";
                pendingNodes.push(front->left);
            } else {
                cout << -1 << " ";
            }
            cout << "R:";
            if(front->right != NULL) {
                cout << front->right->data;
                pendingNodes.push(front->right);
            } else {
                cout << -1;
            }
            cout << endl;
        }
    }

public:
    BST() {
        root = NULL;
    }

    ~BST() {
        delete root;
    }

    bool findElement(int data) {
        return findElement(root, data);
    }

    void insert(int data) {
        this->root = insert(this->root, data);
    }

    void deleteData(int data) {
        root = deleteData(root, data);
    }

    void printTree() {
        printTree(root);
    }
};

int main() {
    BST B;
    B.insert(50);
    B.insert(30);
    B.insert(70);
    B.insert(40);
    B.insert(60);
    B.insert(80);
    // B.insert(6);
    B.printTree();
    cout << B.findElement(100) << endl;
    B.deleteData(50);
    B.printTree();
    return 0;
}