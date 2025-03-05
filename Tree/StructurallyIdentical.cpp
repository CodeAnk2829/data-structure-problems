// Program to check whether two generic trees are identical or not
#include <bits/stdc++.h>
#include "InputLevelWise.cpp"

using namespace std;
bool structurallyIdentical(TreeNode<int>* root1, TreeNode<int>* root2) {
    if(root1 == NULL && root2 == NULL) {
        return true;
    }

    if(root1 == NULL || root2 == NULL) {
        return false;
    }

    bool flag = false;
    if((root1->data == root2->data) && (root1->children.size() == root2->children.size())) {
        flag = true;
        for(int i = 0; i < root1->children.size(); ++i) {
            flag = flag && structurallyIdentical(root1->children[i], root2->children[i]);
        }
    }
    return flag;
}
int main() {
    TreeNode<int>* root1 = takeInputLevelWise();
    TreeNode<int>* root2 = takeInputLevelWise();
    if(structurallyIdentical(root1, root2)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    delete root1;
    delete root2;
    return 0;
}