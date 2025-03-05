/*For a given a Binary Tree of type integer, find and return the minimum and the maximum data values.
Return the output as an object of Pair class, which is already created.*/
#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;
pair<int, int> MaxMina(BinaryTreeNode<int>* root) {
    if(!root) {
        pair<int, int> p;
        p.first = INT_MAX;
        p.second = INT_MIN;
        return p;
    }
    pair<int, int> left = MaxMina(root->left);
    pair<int, int> right = MaxMina(root->right);
    int lmin = left.first;
    int lmax = left.second;
    int rmin = right.first;
    int rmax = right.second;
    pair<int, int> ans;
    ans.first = min(root->data, min(lmin, rmin));
    ans.second = max(root->data, max(lmax, rmax));
    return ans;
}