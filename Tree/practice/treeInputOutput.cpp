#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class TreeNode {
public:
    T val;
    vector<TreeNode*> children;

    TreeNode(T val) {
        this->val = val;
    }
    ~TreeNode() {
        for(auto child : this->children) {
            delete(child);
        }
    }
};

TreeNode<int>* takeInput() {
    int rootVal;
    cout << "Enter root data: "<< endl;
    cin >> rootVal;
    TreeNode<int> *root = new TreeNode<int>(rootVal);

    int n;
    cout << "Enter number of children" << endl;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

void printTree(TreeNode<int>* root) {
    if(!root) return;
    cout << root->val << ": ";
    for(int i = 0; i < root->children.size(); i++) {
        cout << root->children[i]->val << ", ";
    }
    cout << endl;
    for(int i = 0; i < root->children.size(); i++) {
        printTree(root->children[i]);
    }
}


int main() {
    TreeNode<int> *root = takeInput();
    printTree(root);
    return 0;
}