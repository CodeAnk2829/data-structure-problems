// Function to measure the maximum distance between any two nodes in the given binary tree
#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;
pair<int, int> heightDiameter(BinaryTreeNode<int>* root) {
    if(!root) {
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