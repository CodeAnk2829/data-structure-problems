// Program to build a BST using a sorted array
#include <bits/stdc++.h>
using namespace std;
class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

BinaryTreeNode* helper(vector<int> &v, int l, int r)
{
    if (l > r)
        return NULL;
    int mid = (l + r) / 2;
    BinaryTreeNode* root = new BinaryTreeNode (v[mid]);
    root->left = helper(v, l, mid - 1);
    root->right = helper(v, mid + 1, r);
    return root;
}

BinaryTreeNode* sortedArrayToBST(vector<int> &v)
{
    return helper(v, 0, v.size() - 1);
}

void printTree(BinaryTreeNode *root)
{
    if (!root)
        return;
    queue<BinaryTreeNode*> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        BinaryTreeNode *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << " : L:";
        if (front->left != NULL)
        {
            cout << front->left->data << " ";
            pendingNodes.push(front->left);
        }
        else
        {
            cout << -1 << " ";
        }
        cout << "R:";
        if (front->right != NULL)
        {
            cout << front->right->data;
            pendingNodes.push(front->right);
        }
        else
        {
            cout << -1;
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter no. of elements: ";
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    BinaryTreeNode* root = sortedArrayToBST(v);
    printTree(root);
    return 0;
}