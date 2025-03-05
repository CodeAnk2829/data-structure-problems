// Program to count leaf nodes of a given tree
#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;
int countLeafNodes(TreeNode<int> *root) {
    if(root == NULL) return 0;
    if(root->children.empty()) return 1;
    int count = 0;
    for(int i = 0; i < root->children.size(); ++i) {
        count += countLeafNodes(root->children[i]);
    }
    return count;
}