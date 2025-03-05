#include <bits/stdc++.h> 
using namespace std;

class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
BinaryTreeNode* insertNode(BinaryTreeNode *root, int data)
{
    if (root == NULL)
        return new BinaryTreeNode(data);
    if (data >= root->data) {
        root->right = insertNode(root->right, data);
    }
    else if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    return root;
}
bool recursiveSearch(BinaryTreeNode *root, int data)
{
    if (root == NULL) {
        return false;
    }
    bool flag = false;
    if (root->data > data) {
       flag = recursiveSearch(root->left, data);
    }
    else if (root->data <= data) {
       flag = recursiveSearch(root->right, data);
    }
    return flag;
}
bool iterativeSearch(BinaryTreeNode *root, int data)
{
    if (root == NULL)
        return false;
    while (root != NULL) {
        if (root->data > data) {
            root = root->left;
        }
        else if (root->data <= data) {
            root = root->right;
        } else {
            return true;
        }
    }

    return false;
}
int findMax(BinaryTreeNode *root)
{
    if (root == NULL)
        return INT_MAX;
    while (root->right != NULL) {
        root = root->right;
    }
    return root->data;
}
int findMin(BinaryTreeNode *root)
{
    if (root == NULL)
        return INT_MIN;
    while (root->left != NULL) {
        root = root->left;
    }
    return root->data;
}
BinaryTreeNode *minValueBinaryTreeNode(BinaryTreeNode *root)
{
    BinaryTreeNode *temp = root;
    while (temp != NULL && temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}
BinaryTreeNode *getSuccessor(BinaryTreeNode *root)
{
    root = root->right;
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root;
}

int successor(BinaryTreeNode *root, int val)
{
    BinaryTreeNode *result = NULL;
    while (root != NULL) {
        if (root->data == val)
            return root->right->data;
        else if (root->data < val)
            root = root->right;
        else {
            result = root;
            root = root->left;
        }
    }
    return -1;
}

BinaryTreeNode *deleteBinaryTreeNode(BinaryTreeNode *root, int data)
{
    if (root == NULL) return NULL;

    if (data < root->data)
        root->left = deleteBinaryTreeNode(root->left, data);
    else if (data >= root->data)
        root->right = deleteBinaryTreeNode(root->right, data);
    else {
        if (root->left == NULL && root->right == NULL)
            return NULL;
        else if (root->left == NULL) {
            BinaryTreeNode *temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL)
        {
            BinaryTreeNode *temp = root->left;
            delete root;
            return temp;
        }
        BinaryTreeNode *temp = minValueBinaryTreeNode(root->right);

        root->data = temp->data;
        root->right = deleteBinaryTreeNode(root->right, temp->data);
    }
    return root;
}
int main()
{
    BinaryTreeNode *root = NULL;
    root = insertNode(root, 4);
    root = insertNode(root, 8);
    root = insertNode(root, 2);
    root = insertNode(root, 23);
    root = insertNode(root, 15);
    root = insertNode(root, 37);
    root = insertNode(root, 79);
    cout << "Enter a number: ";
    int key;
    cin >> key;
    if (iterativeSearch(root, key)) {
        cout << "Key found!" << endl;
    }
    else {
        cout << "Key not found!" << endl;
    }
    cout << "Enter a number: ";
    int val;
    cin >> val;
    if (recursiveSearch(root, val)) {
        cout << "Key found!" << endl;
    }
    else {
        cout << "Key not found!" << endl;
    }
    cout << "Maximum node value: " << findMax(root) << endl;
    cout << "Minimum node value: " << findMin(root) << endl;

    cout << "Enter the element to find it's successor: ";
    cin >> key;
    cout << "Successor of " << key << " is: " << successor(root, key) << endl;
    cout << "Enter the element to be deleted: ";
    cin >> key;
    root = deleteBinaryTreeNode(root, key);

    return 0;
}
