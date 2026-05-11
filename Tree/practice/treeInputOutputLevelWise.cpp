#include <iostream>
#include <vector>
#include <queue>

using namespace std;

template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<int>*> children;

    TreeNode(T data) {
        this->data = data;
    }

    ~TreeNode() {
        for(auto child : this->children) {
            delete(child);
        }
    }
};

TreeNode<int>* takeInput() {
    int rootData;
    cout << "Enter node data: ";
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()) {
        TreeNode<int>* node = pendingNodes.front();
        pendingNodes.pop();

        int n;
        cout << "Enter number of children: ";
        cin >> n;
        cout << "Enter children: ";
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
        cout << node->data << ": ";
        pendingNodes.pop();
        for(auto child : node->children) {
            cout << child->data << ",";
            pendingNodes.push(child);
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    TreeNode<int>* root = takeInput();
    printTree(root);
    return 0;
}