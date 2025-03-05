#include "BinaryTreeNode.h"
vector<int>* getRootToNodePath(BinaryTreeNode<int>* root, int data) {
    if(!root) return NULL;
    if(root->data == data) {
        vector<int>* output = new vector<int> ();
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
    int k;
    cin >> k;
    vector<int>* output = getRootToNodePath(root, k);
    for(int i = 0; i < output->size(); ++i) {
        cout << output->at(i) << " ";
    }
    return 0;
}