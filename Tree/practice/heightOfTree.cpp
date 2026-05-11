#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode*> children;

    TreeNode(T data) {
        this->data = data;
    }
};

TreeNode<int>* takeInput() {
    int rootData;
    cout << "enter root: ";
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()) {
        TreeNode<int>* node = pendingNodes.front();
        pendingNodes.pop();
        cout << "enter num of children: ";
        int n;
        cin >> n;
        cout << "enter " << n << "children";
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            TreeNode<int>* child = new TreeNode<int>(x);
            node->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void printTree(TreeNode<int>* root) {
    if(!root) return;
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()) {
        TreeNode<int>* node = pendingNodes.front();
        pendingNodes.pop();
        cout << node->data << ": ";
        for(TreeNode<int>* child : node->children) {
            cout << child->data << ", ";
            pendingNodes.push(child);
        }
        cout << endl;
    }
}

int findHeight(TreeNode<int>* root) {
    if(!root) return 0;
    int currNodeHeight = 0;
    for(auto child : root->children) {
        currNodeHeight = max(currNodeHeight, findHeight(child));
    }
    return 1 + currNodeHeight;
}

int main() {
    TreeNode<int>* root = takeInput();
    printTree(root);
    cout << findHeight(root) << endl;
    return 0;
}