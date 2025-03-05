#include <bits/stdc++.h>
using namespace std;
template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<int>* left;
    BinaryTreeNode<int>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
        delete left;
        delete right;
    }
};

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()) {
        BinaryTreeNode<int>* currentNode = pendingNodes.front();
        pendingNodes.pop();
        
        int leftChildData;
        cin >> leftChildData;
        if(leftChildData != -1) {
            BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int> (leftChildData);
            currentNode->left = leftChild;
            pendingNodes.push(leftChild);
        }

        int rightChildData;
        cin >> rightChildData;
        if(rightChildData != -1) {
            BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int> (rightChildData);
            currentNode->right = rightChild;
            pendingNodes.push(rightChild);
        }
    }
    return root;
}

void print(BinaryTreeNode<int>* root) {
    if(!root) {
        return;
    }

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()) {
        BinaryTreeNode<int>* currentNode = pendingNodes.front();
        pendingNodes.pop();
        cout << currentNode->data << " : ";

        if(currentNode->left != NULL) {
            cout << "L " << currentNode->left->data << " ";
            pendingNodes.push(currentNode->left);
        } else {
            cout << "L -1" << " ";
        }

        if(currentNode->right != NULL) {
            cout << "R " << currentNode->right->data << endl;
            pendingNodes.push(currentNode->right);
        } else {
            cout << "R -1" << endl;
        }
    }
}

int countNodes(BinaryTreeNode<int>* root) {
    if(!root) {
        return 0;
    }

    int count = 1;
    count += (countNodes(root->left) + countNodes(root->right));
    return count;
}

bool isNodePresent(BinaryTreeNode<int>* root, int n) {
    if(!root) {
        return false;
    }
    if(root->data == n) {
        return true;
    }
    return isNodePresent(root->left, n) || isNodePresent(root->right, n);
}

int BTheight(BinaryTreeNode<int>* root) {
    if(!root) {
        return 0;
    }

    int height = 0;
    int leftHeight = BTheight(root->left);
    int rightHeight = BTheight(root->right);
    
    height = 1 + max(leftHeight, rightHeight);
    return height;
}

void preorder(BinaryTreeNode<int>* root) {
    if(!root) {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(BinaryTreeNode<int>* root) {
if(!root) {
    return;
}
postorder(root->left);
postorder(root->right);
cout << root->data << " ";
}

void inorder(BinaryTreeNode<int>* root) {
    if(!root) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void levelOrder(BinaryTreeNode<int>* root) {
    if(!root) return;
    cout << root->data << endl;
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()) {
        int size = pendingNodes.size();
        for(int i = 0; i < size; ++i) {
            BinaryTreeNode<int>* currentNode = pendingNodes.front();
            pendingNodes.pop();
            
            if(currentNode->left != NULL) {
                cout << currentNode->left->data << " ";
                pendingNodes.push(currentNode->left);
            }
            if(currentNode->right != NULL) {
                cout << currentNode->right->data << " ";
                pendingNodes.push(currentNode->right);
            }
        }
        cout << endl;
    }
}

void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    if(!root) return;
    cout << root->data << endl;
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()) {
        int size = pendingNodes.size();
        for(int i = 0; i < size; ++i) {
            BinaryTreeNode<int>* currentNode = pendingNodes.front();
            pendingNodes.pop();

            if(currentNode->right != NULL) {
                cout << currentNode->right->data << " ";
                pendingNodes.push(currentNode->right);
            }
            if(currentNode->left != NULL) {
                cout << currentNode->left->data << " ";
                pendingNodes.push(currentNode->left);
            }
        }
        cout << endl;
    }
}

vector<vector<int>> levelOrderBottom(BinaryTreeNode<int>* root) {
    vector<vector<int>> ans;
    stack<vector<int>> s;
    if(!root) return ans;
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(!pendingNodes.empty()) {
        vector<int> level;
        int size = pendingNodes.size();
        for(int i = 0; i < size; ++i) {
            BinaryTreeNode<int>* currentNode = pendingNodes.front();
            pendingNodes.pop();
            if(currentNode->left != NULL) {
                pendingNodes.push(currentNode->left);
            }
            if(currentNode->right != NULL) {
                pendingNodes.push(currentNode->right);
            }
            level.push_back(currentNode->data);
        }
        s.push(level);
    }
    while(!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

// Function to construct a new binary tree from given inorder and preorder traversals

BinaryTreeNode<int>* constructBT(int* in, int* pre, int inS, int inE, int preS, int preE) {
    // Base case
    if(inS > inE) return NULL;

    int rootData = pre[preS];
    BinaryTreeNode<int>* root = new BinaryTreeNode<int> (rootData);

    // Finding root index
    int rootIndex = -1;
    for (int i = inS; i <= inE; ++i)
    {
        if (rootData == in[i])
        {
            rootIndex = i;
            break;
        }
    }
    cout << rootIndex << endl;
    int leftInS = inS;
    int leftInE = rootIndex - 1;
    int leftPreS = preS + 1;
    int leftPreE = leftInE - leftInS + leftPreS;

    int rightInS = rootIndex + 1;
    int rightInE = inE;
    int rightPreS = leftPreE + 1;
    int rightPreE = preE;

    BinaryTreeNode<int>* leftSubTree = constructBT(in, pre, leftInS, leftInE, leftPreS, leftPreE);
    BinaryTreeNode<int>* rightSubTree = constructBT(in, pre, rightInS, rightInE, rightPreS, rightPreE);
    root->left = leftSubTree;
    root->right = rightSubTree;
    return root;
}

pair<int, int> heightDiameter(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        pair<int, int> temp = {0, 0};
        return temp;
    }

    pair<int, int> leftChild = heightDiameter(root->left);
    pair<int, int> rightChild = heightDiameter(root->right);

    int lh = leftChild.first;
    int rh = rightChild.first;
    int ld = leftChild.second;
    int rd = rightChild.second;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));
    pair<int, int> ans = {height, diameter};
    return ans;
}

pair<int, int> getMaxMin(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        pair<int, int> temp = {INT_MIN, INT_MAX};
        return temp;
    }

    pair<int, int> getLeftMaxMin = getMaxMin(root->left);
    pair<int, int> getRightMaxMin = getMaxMin(root->right);

    int leftMax = getLeftMaxMin.first;
    int leftMin = getLeftMaxMin.second;
    int rightMax = getRightMaxMin.first;
    int rightMin = getRightMaxMin.second;

    int maximum = max(root->data, max(leftMax, rightMax));
    int minimum = min(root->data, min(leftMin, rightMin));

    pair<int, int> ans = {maximum, minimum};
    return ans;
}

BinaryTreeNode<int>* nextLarger(BinaryTreeNode<int> * root, int x) {
    if(root == NULL) {
        return NULL;
    }
    BinaryTreeNode<int>* ans = (root->data > x) ? root : NULL;

    BinaryTreeNode<int>* leftAns = nextLarger(root->left, x);
    BinaryTreeNode<int>* rightAns = nextLarger(root->right, x);

    BinaryTreeNode<int>* temp = NULL;
    if(leftAns != NULL && rightAns != NULL) {
        if(leftAns->data < rightAns->data) {
            temp = leftAns;
        } else {
            temp = rightAns;
        }
    } else if(leftAns != NULL) {
        temp = leftAns;
    } else if(rightAns != NULL) {
        temp = rightAns;
    }

    if(ans == NULL && temp == NULL) {
        return NULL;
    }

    if(ans != NULL && temp != NULL) {
        return (ans->data < temp->data) ? ans : temp;
    } else {
        return (ans != NULL) ? ans : temp;
    }
}

pair<int, bool> isBalancedHelper(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        pair<int, bool> p = {0, true};
        return p;
    }
    pair<int, bool> leftAns = isBalancedHelper(root->left);
    pair<int, bool> rightAns = isBalancedHelper(root->right);

    bool result = false;
    if(leftAns.second && rightAns.second && abs(leftAns.first - rightAns.first) <= 1) {
        result = true;
    }
    int height = 1 + max(leftAns.first, rightAns.first);
    pair<int, bool> finalAns = {height, result};
    return finalAns;
}

bool isBalanced(BinaryTreeNode<int>* root) {
    pair<int, bool> ans = isBalancedHelper(root);
    return ans.second;
}

BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int>* root) {
    if(!root) {
        return NULL;
    }
    if(!root->left && !root->right) {
        delete root;
        return NULL;
    }
    root->left = removeLeafNodes(root->left);
    root->right = removeLeafNodes(root->right);
    return root;
}
 
int main() {
    BinaryTreeNode<int>* root = takeInput();
    // print(root);
    // cout << countNodes(root) << endl;

    // int n;
    // cin >> n;
    // if(isNodePresent(root, n)) {
    //     cout << "true" << endl;
    // } else {
    //     cout << "false" << endl;
    // }

    // cout << BTheight(root) << endl;
    // preorder(root);
    // cout << endl;
    // postorder(root);
    // cout << endl;
    // inorder(root);
    // cout << endl;

    // levelOrder(root);
    // mirrorBinaryTree(root);
    // vector<vector<int>> v = levelOrderBottom(root);
    // for(int i = 0; i < v.size(); ++i) {
    //     for(auto &p : v[i]) {
    //         cout << p << " ";
    //     }
    //     cout << endl;
    // }

    // int n;
    // cin >> n;
    // int pre[n], in[n];
    // for(int i = 0; i < n; ++i) {
    //     cin >> pre[i];
    // }
    // for(int i = 0; i < n; ++i) {
    //     cin >> in[i];
    // }

    // BinaryTreeNode<int>* newBinaryTree = constructBT(in, pre, 0, n - 1, 0, n - 1);
    // print(newBinaryTree);

    // pair<int, int> maxMina = getMaxMin(root);
    // cout << maxMina.first << " " << maxMina.second << endl;

    // BinaryTreeNode<int>* nextLargerVal = nextLarger(root, n);
    // if(nextLargerVal == NULL) {
    //     cout << -1 << endl;
    // } else {
    //     cout << nextLargerVal->data << endl;
    // }

    // pair<BinaryTreeNode<int> *, BinaryTreeNode<int> *> p = getSecondLargest(root);
    // cout << p.first << " " << p.second << endl;

    cout << isBalanced(root) << endl;
    BinaryTreeNode<int>* removeLeaves = removeLeafNodes(root);
    levelOrder(removeLeaves);

    // Delete
    delete root;
    return 0;
}