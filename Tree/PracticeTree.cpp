#include <bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) {
        this->data = data;
    }

    ~TreeNode() {
        for(int i = 0; i < children.size(); ++i) {
            delete children[i];
        }
    }
};

TreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int> (rootData);

    queue<TreeNode<int>*> parent;
    parent.push(root); 
    while(!parent.empty()) {
        TreeNode<int>* front = parent.front();
        parent.pop();
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            TreeNode<int>* child = new TreeNode<int>(x);
            front->children.push_back(child);
            parent.push(child);
        }
    }
    return root;
}

void print(TreeNode<int>* root) {
    if(root == NULL) {
        return;
    }
    queue<TreeNode<int>*> pendingNode;
    pendingNode.push(root);
    while(!pendingNode.empty()) {
        TreeNode<int>* front = pendingNode.front();
        pendingNode.pop();
        cout << front->data << " : ";
        for(int i = 0; i < front->children.size(); ++i) {
            cout << front->children[i]->data << " ";
            pendingNode.push(front->children[i]);
        }
        cout << endl;
    }
}

int countNode(TreeNode<int>* root) {
    if(root == NULL) {
        return 0;
    }
    int ct  = 1;
    for(int i = 0; i < root->children.size(); ++i) {
        ct += countNode(root->children[i]);
    }
    return ct;
}

int sumOfNodes(TreeNode<int>* root) {
    if(root == NULL) {
        return 0;
    }
    int sum = root->data;
    for(int i = 0; i < root->children.size(); ++i) {
        sum += sumOfNodes(root->children[i]);
    }
    return sum;
}

TreeNode<int>* minNode(TreeNode<int>* root) {
    if(root == NULL) {
        return NULL;
    }
    TreeNode<int>* minimum = root;
    for(int i = 0; i < root->children.size(); ++i) {
        TreeNode<int>* dummy_so_far = minNode(root->children[i]);
        if(minimum->data > dummy_so_far->data) {
            minimum = dummy_so_far;
        }
    }
    return minimum;
}

TreeNode<int>* maxNode(TreeNode<int>* root) {
    if(root == NULL) {
        return NULL;
    }
    TreeNode<int>* maximum = root;
    for(int i = 0; i < root->children.size(); ++i) {
        TreeNode<int>* maxNode_so_far = maxNode(root->children[i]);
        if(maximum->data < maxNode_so_far->data) {
            maximum = maxNode_so_far;
        }
    }
    return maximum;
}

int findHeight(TreeNode<int>* root) {
    if(root == NULL) {
        return 0;
    }
    int height = 1;
    for(int i = 0; i < root->children.size(); ++i) {
        int h = findHeight(root->children[i]);
        height = max(height,  1 + h);
    }
    return height;
}

void printATLevelK(TreeNode<int>* root, int k) {
    if(root == NULL) {
        return;
    }
    if(k == 0) {
        cout << root->data << " ";
    }
    for(int i = 0; i < root->children.size(); ++i) {
        printATLevelK(root->children[i], k - 1);
    }
}

int countLeafNodes(TreeNode<int>* root) {
    if(root == NULL) {
        return 0;
    }

    if(root->children.size() == 0) {
        return 1;
    }

    int leafCount = 0;
    for(int i = 0; i < root->children.size(); ++i) {
        leafCount += countLeafNodes(root->children[i]);
    }
    return leafCount;
}

void preorder(TreeNode<int>* root) {
    if(!root) return;

    cout << root->data << " ";
    for(int i = 0; i < root->children.size(); ++i) {
        preorder(root->children[i]);
    }
}

void postorder(TreeNode<int>* root) {
    if(!root) return;
    for(int  i = 0; i < root->children.size(); ++i) {
        postorder(root->children[i]);
    }
    cout << root->data << " ";
}

pair<TreeNode<int>*, int> nodeWithMaxChildSum(TreeNode<int>* root) {
    if(!root) {
        pair<TreeNode<int>*, int> p = {NULL, 0};
        return p;
    }

    TreeNode<int>* maxChildSumNode = root;
    int maxSum = root->data;
    for(int i = 0; i < root->children.size(); ++i) {
        maxSum = root->children[i]->data;
    }
    for(int i = 0; i < root->children.size(); ++i) {
        pair<TreeNode<int>*, int> temp = nodeWithMaxChildSum(root->children[i]);
        if(maxSum < temp.second) {
            maxChildSumNode = temp.first;
            maxSum = temp.second;
        }
    }
    pair<TreeNode<int>*, int> p = {maxChildSumNode, maxSum};
    return p;
}

bool containsX(TreeNode<int>* root, int x) {
    if(!root) return false;

    if(root->data == x) {
        return true;
    }

    bool flag = false;
    for(int i = 0; i < root->children.size(); ++i) {
        flag = flag || containsX(root->children[i], x);
    }
    return flag;
} 

bool isSameTree(TreeNode<int>* root1, TreeNode<int>* root2) {
    if(!root1 && !root2) {
        return true;
    }
    if(!root1 || !root2) {
        return false;
    }

    bool flag = false;
    if((root1->data == root2->data) && (root1->children.size() == root2->children.size())) {
        flag = true;
        for(int i = 0; i < root1->children.size(); ++i) {
            flag = flag && isSameTree(root1->children[i], root2->children[i]);
        }
    }
    return flag;
}

TreeNode<int>* nextLarger(TreeNode<int>* root, int n) {
    if(!root) {
        return NULL;
    }

    TreeNode<int>* ans = NULL;
    
    if(root->data > n) {
        ans = root;
    } 

    for(int i = 0; i < root->children.size(); ++i) {
        TreeNode<int>* temp = nextLarger(root->children[i], n);
        if(ans == NULL && temp != NULL) {
            ans = temp;
        } else if(temp != NULL && (ans->data > temp->data)) {
            ans = temp;
        }
    }
    return ans;
}

TreeNode<int>* secondLargestHelper(TreeNode<int>* root, int largest) {
    TreeNode<int>* ans = NULL;

    if(root->data < largest)  {
        ans = root;
    }

    for(int i = 0; i < root->children.size(); ++i) {
        TreeNode<int>* temp = secondLargestHelper(root->children[i], largest);
        if(ans == NULL && temp != NULL) {
            ans = temp;
        } else if(temp != NULL && (ans->data < temp->data)) {
            ans = temp;
        }
    }
    return ans;
}

TreeNode<int>* secondLargest(TreeNode<int>* root) {
    if(!root) {
        return NULL;
    }  
    if(root->children.size() == 0) {
        return NULL;
    }
    TreeNode<int>* largestNode = maxNode(root);
    return secondLargestHelper(root, largestNode->data);
}

int main() {
    TreeNode<int>* root = takeInput();
    // TreeNode<int>* root2 = takeInput();
    print(root);

    // cout << countNode(root) << endl;
    // cout << sumOfNodes(root) << endl;
    // TreeNode<int>* smallestNode = minNode(root);
    // cout << smallestNode->data << endl;

    // TreeNode<int>* largestNode = maxNode(root);
    // cout << largestNode->data << endl;

    // cout << findHeight(root) << endl;
    // int k;
    // cin >> k;
    // printATLevelK(root, k); 
    // cout << countLeafNodes(root) << endl;
    // preorder(root);
    // pair<TreeNode<int>*, int> ans = nodeWithMaxChildSum(root);
    // cout << ans.first->data << endl;
    // int x;
    // cin >> x;
    // cout << containsX(root, x) << endl;
    // print(root2);
    // cout << isSameTree(root, root2) << endl;

    // int n;
    // cin >> n;
    // TreeNode<int>* nxtLgr = nextLarger(root, n);
    // if(!nxtLgr) {
    //     cout << -1 << endl;
    // } else {
    //     cout << nxtLgr->data << endl;
    // }

    TreeNode<int>* secondLargestNode = secondLargest(root);
    if(!secondLargestNode) {
        return -1;
    } else {
        cout << secondLargestNode->data << endl;
    }

    // Delete Tree
    delete root;
    return 0;
}