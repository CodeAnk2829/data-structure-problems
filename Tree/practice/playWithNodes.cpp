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
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()) {
        TreeNode<int>* node = pendingNodes.front();
        pendingNodes.pop();
        int n;
        cin >> n;
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

int countNodes(TreeNode<int>* root) {
    if(!root) return 0;
    int count = 0;
    for(TreeNode<int>* child : root->children) {
        count += countNodes(child);
    }
    return 1 + count;
}

int countLeafNodes(TreeNode<int>* root) {
    if(!root) return 0;
    if(root->children.size() == 0) return 1;
    int count = 0;
    for(TreeNode<int>* child : root->children) {
        count += countLeafNodes(child);
    }
    return count;
}

bool doesNodeExist(TreeNode<int>* root, int target) {
    if(!root) return false;
    if(root->data == target) return true;
    for(TreeNode<int>* child : root->children) {
        if(doesNodeExist(child, target)) return true;
    }
    return false;
}

TreeNode<int>* largestNode(TreeNode<int>* root) {
    if(!root) return new TreeNode<int>(INT_MIN);
    // base case
    if(root->children.size() == 0) return root;
    TreeNode<int>* maxNode = new TreeNode<int>(INT_MIN);
    for(TreeNode<int>* child : root->children) {
        TreeNode<int>* temp = largestNode(child);
        if(temp->data > maxNode->data) {
            maxNode = temp;
        }
    }
    return maxNode;
}

pair<TreeNode<int>*, int> findNodeWithMaxChildren(TreeNode<int>* root) {
    if(!root) return {NULL, INT_MIN};
    // base case
    if(root->children.size() == 0) return {root, 0};
    pair<TreeNode<int>*, int> ans = {root, root->children.size()};
    for(TreeNode<int>* child : root->children) {
        pair<TreeNode<int>*, int> nodeWithChildren = findNodeWithMaxChildren(child);
        if(nodeWithChildren.second > ans.second) {
            ans = nodeWithChildren;
        }
    }
    return ans;
}

int main() {
    TreeNode<int>* root = takeInput();
    printTree(root);
    cout << countNodes(root) << endl;
    cout << countLeafNodes(root) << endl;
    int target;
    cin >> target;
    cout << doesNodeExist(root, target) << endl;
    TreeNode<int>* maxNode = largestNode(root);
    cout << maxNode->data << endl;
    pair<TreeNode<int>*, int> maxChildrenNode = findNodeWithMaxChildren(root);
    cout << maxChildrenNode.first->data << ": " << maxChildrenNode.second << endl;
    delete root;
    return 0;
}