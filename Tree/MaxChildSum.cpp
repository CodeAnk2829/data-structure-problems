// Funtion to find the node having maximum child sum recursively in optimised way
#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
TreeNode<int>* superNode(TreeNode<int>* root) {
    if(root == NULL) return NULL;
    int sum = root->data;
    for(int i = 0; i < root->children.size(); ++i) {
        sum += root->children[i]->data;
    }
    TreeNode<int>* ans = new TreeNode<int> (sum);
    ans->children.push_back(root);
    for(int i = 0; i < root->children.size(); ++i) {
        TreeNode<int>* x = superNode(root->children[i]);
        if(sum < x->data) {
            ans = x;
            sum = ans->data;
        }
    }
    return ans;
}