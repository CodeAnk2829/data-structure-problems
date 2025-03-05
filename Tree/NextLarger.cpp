// Program to find the next greater element than a given key in the given tree
#include <bits/stdc++.h>
#include "InputLevelWise.cpp"
using namespace std;
TreeNode<int>* NextLarger(TreeNode<int>* root, int key) {
    if(root == NULL) return root;
    TreeNode<int>* ans = (key < root->data) ? root : NULL;
    for(int i = 0; i < root->children.size(); ++i) {
        TreeNode<int>* x = NextLarger(root->children[i], key);
        if(ans == NULL) {
            if(x->data > key) ans = x;
        } else if(x->data < ans->data) 
                ans = x;
    }
    return ans; 
}
int main() {
    int key;
    cin >> key;
    TreeNode<int>* root = takeInputLevelWise();
    TreeNode<int>* ans = NextLarger(root, key);
    if(ans != NULL)
        cout << ans->data << endl;
    delete root;
    return 0;
}