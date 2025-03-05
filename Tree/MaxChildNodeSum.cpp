// Program to find and return that node which has maximum child sum and sum of itself
#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
TreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int> (rootData);
    queue<TreeNode<int>*> queuenode;
    queuenode.push(root);
    while(queuenode.empty() != true) {
        TreeNode<int> *front = queuenode.front();
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
void printTree(TreeNode<int> *root) {
    if(root == NULL) return;
    queue<TreeNode<int>*> queuenode;
    queuenode.push(root);
    while(queuenode.empty() != true) {
        TreeNode<int> *front = queuenode.front();
        cout << front->data << " : ";
        queuenode.pop();
        for(int i = 0; i < front->children.size(); ++i) {
            cout << front->children[i]->data << " ";
            queuenode.push(front->children[i]);
        }
        cout << endl;
    }
}

// Finding the node with maximum child sum recursively
TreeNode<int> *superNode(TreeNode<int> *root)
{
    if (root == NULL)
        return NULL;
    int sum = root->data;
    for (int i = 0; i < root->children.size(); ++i)
    {
        sum += root->children[i]->data;
    }
    TreeNode<int> *ans = new TreeNode<int>(sum);
    ans->children.push_back(root);
    for (int i = 0; i < root->children.size(); ++i)
    {
        TreeNode<int> *x = superNode(root->children[i]);
        if (sum < x->data)
        {
            ans = x;
            sum = ans->data;
        }
    }
    return ans;
}
int main()
{
    TreeNode<int> *root = takeInput();
    printTree(root);
    TreeNode<int> *ans = superNode(root);
    cout << "The node having maximum child sum is " << ans->children[0]->data << endl;
    delete root;
    return 0;
}