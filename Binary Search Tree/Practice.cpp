#include "BinaryTreeNode.h"
BinaryTreeNode<int>* searchElement(BinaryTreeNode<int>* root, int n) {
    if(!root) {
        return NULL;
    }
    if(root->data == n) {
        return root;
    }
    if(root->data < n) {
        return searchElement(root->right, n);
    } else {
        return searchElement(root->left, n);
    }
}

vector<int> printInRange(BinaryTreeNode<int>* root, int low, int high) {
    if(!root) {
        vector<int> v;
        return v;
    }
    if(root->data > high) {
        return printInRange(root->left, low, high);
    } else if(root->data < low) {
        return printInRange(root->right, low, high);
    } else {
        vector<int> leftAns = printInRange(root->left, low, high);
        vector<int> rightAns = printInRange(root->right, low, high);
        vector<int> ans = leftAns;
        ans.push_back(root->data);
        for(auto &p : rightAns) {
            ans.push_back(p);
        }
        return ans;
    }
}

// Naive approach to check BST
// TC - O(n.h), where h = height of the tree
int maximum(BinaryTreeNode<int>* root) { // Function to find the greatest node
    if(!root) {
        return INT_MIN;
    }
    int leftMax = maximum(root->left);
    int rightMax = maximum(root->right);

    return max(root->data, max(leftMax, rightMax));
}

int minimum(BinaryTreeNode<int>* root) { // Function to find the least node
    if(!root) {
        return INT_MAX;
    }
    int leftMin = minimum(root->left);
    int rightMin = minimum(root->right);
     
    return min(root->data, min(leftMin, rightMin));
}

bool isBSTMethod1(BinaryTreeNode<int>* root) { // First method to whether a given binary tree is BST or not
    if(!root) {
        return true;
    }
    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);
    
    int ans = (root->data > leftMax) && (root->data <= rightMin) && (isBSTMethod1(root->left)) && (isBSTMethod1(root->right));
    return ans;
}


// Optimized approach (Bottom-Up)
// TC - O(N)
class isBSTReturn {
public: 
    bool isBST;
    int maxima;
    int minima;
};

isBSTReturn checkBST(BinaryTreeNode<int>* root) {
    if(!root) {
        isBSTReturn output = {true, INT_MIN, INT_MAX};
        return output;
    }
    isBSTReturn leftAns = checkBST(root->left);
    isBSTReturn rightAns = checkBST(root->right);

    int globalMax = max(root->data, max(leftAns.maxima, rightAns.maxima));
    int globalMin = min(root->data, min(leftAns.minima, rightAns.minima));
    bool isBSTFinal = (root->data > leftAns.maxima) && (root->data <= rightAns.minima) && (leftAns.isBST) && (rightAns.isBST);

    isBSTReturn output = {isBSTFinal, globalMax, globalMin};
    return output;
}

bool isBSTMethod2(BinaryTreeNode<int>* root) { // Second method to check whether a given binary tree is BST or not
    isBSTReturn ans = checkBST(root);
    return ans.isBST;
}

// Optimized approach--> short code than the previous one
// Top-Down approach
// TC - O(n)
bool isBSTMethod3(BinaryTreeNode<int>* root, int minima = INT_MIN, int maxima = INT_MAX) {
    if(!root) {
        return true;
    }
    if(root->data <= minima || root->data > maxima) {
        return false;
    }
    bool isLeftOk = isBSTMethod3(root->left, minima, root->data - 1);
    bool isRightOk = isBSTMethod3(root->right, root->data, maxima);

    return (isLeftOk && isRightOk);
}

BinaryTreeNode<int>* constructBST(vector<int>& v, int low, int high) {
    if(low > high) {
        return NULL;
    }
    int mid = (low + high) / 2;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int> (v[mid]);
    root->left = constructBST(v, low, mid - 1);
    root->right = constructBST(v, mid + 1, high);

    return root;
}

template <typename T>
class ListNode {
public: 
    T val;
    ListNode<int>* next;

    ListNode(T val) {
        this->val = val;
        next = NULL;
    }

    ~ListNode() {
        delete this->next;
    }
};

pair<ListNode<int>*, ListNode<int>*> createSortedLL(BinaryTreeNode<int>* root) {
    if(!root) {
        pair<ListNode<int>*, ListNode<int>*> dummy = {NULL, NULL};
        return dummy;
    }
    ListNode<int>* newNode = new ListNode<int>(root->data);

    pair<ListNode<int>*, ListNode<int>*> leftLL = createSortedLL(root->left);
    pair<ListNode<int>*, ListNode<int>*> rightLL = createSortedLL(root->right);

    ListNode<int>* lHead = leftLL.first;
    ListNode<int>* lTail = leftLL.second;
    ListNode<int>* rHead = rightLL.first;
    ListNode<int>* rTail = rightLL.second;

    if(lTail != NULL) {
        lTail->next = newNode;
    }
    newNode->next = rHead;

    ListNode<int>* head = (lHead != NULL) ? lHead : newNode;
    ListNode<int>* tail = (rTail != NULL) ? rTail : newNode;

    pair<ListNode<int>*, ListNode<int>*> output = {head, tail};
    return output;
}

ListNode<int>* BSTToSortedLL(BinaryTreeNode<int>* root) {
    pair<ListNode<int>*, ListNode<int>*> ans = createSortedLL(root);
    return ans.first;
}

void printLL(ListNode<int> *head)
{
    if(head == NULL) return;
    ListNode<int> *temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

vector<int>* getRootToNodePath(BinaryTreeNode<int>* root, int data) {
    if(!root) {
        return NULL;
    }
    if(root->data == data) {
        vector<int>* output = new vector<int>;
        output->push_back(root->data);
        return output;
    }
    vector<int>* leftOutput = getRootToNodePath(root->left, data);
    if(leftOutput != NULL) {
        leftOutput->push_back(root->data);
        return leftOutput;
    }
    vector<int>* rightOutput = getRootToNodePath(root->right, data);
    if(rightOutput != NULL) {
        rightOutput->push_back(root->data);
        return rightOutput;
    } else {
        return NULL;
    }
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    // int n;
    // cin >> n;
    // BinaryTreeNode<int>* ans = searchElement(root, n);
    // if(ans != NULL) {
    //     cout << "true" << endl;
    // } else {
    //     cout << "false" << endl;
    // }
    
    // int low, high;
    // cin >> low >> high;
    // vector<int> ans = printInRange(root, low, high);
    // for(auto &p : ans) {
    //     cout << p << " ";
    // }

    // cout << isBSTMethod1(root) << endl;
    // cout << isBSTMethod2(root) << endl;
    // cout << isBSTMethod3(root) << endl;

    // int n;
    // cin >> n;
    // vector<int> v;
    // for(int i = 0; i < n; ++i) {
    //     int x;
    //     cin >> x;
    //     v.push_back(x);
    // }
    // BinaryTreeNode<int>* newRoot = constructBST(v, 0, n - 1);
    // printTree(newRoot);

    // ListNode<int>* sortedLL = BSTToSortedLL(root);
    // printLL(sortedLL);
    // delete sortedLL;

    // int data;
    // cin >> data;
    // vector<int>* output = getRootToNodePath(root, data);
    // for(int i = 0; i < output->size(); ++i) {
    //     cout << output->at(i) << " ";
    // }
    // delete output;
    
    delete root;
    return 0;
}