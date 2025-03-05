#include "BinaryTreeNode.h"
using namespace std;
vector<int>* getRootToNodePath(BinaryTreeNode<int>* root, int k) {
    if(!root) {
        return NULL;
    }
    if(root->data == k) {
        vector<int>* output = new vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int>* leftOutput = getRootToNodePath(root->left, k);
    if(leftOutput != NULL) {
        leftOutput->push_back(root->data);
        return leftOutput;
    }
    vector<int>* rightOutput = getRootToNodePath(root->right, k);
    if(rightOutput != NULL) {
        rightOutput->push_back(root->data);
        return rightOutput;
    } else {
        return NULL;
    }
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    int k;
    cin >> k;
    vector<int>* v = getRootToNodePath(root, k);
    for(int i = 0; i < v->size(); ++i) {
        cout << v->at(i) << " ";
    }
    delete v;
    return 0;
}
