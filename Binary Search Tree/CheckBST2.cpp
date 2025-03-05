// Time Complexity = O(N)
#include "BinaryTreeNode.h"
using namespace std;
class isBSTReturn
{
public:
    bool isBST;
    int maximum;
    int minimum;
};
isBSTReturn isBST2(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        isBSTReturn output;
        output.isBST = true;
        output.maximum = INT_MIN;
        output.minimum = INT_MAX;
        return output;
    }
    isBSTReturn leftOutput = isBST2(root->left);
    isBSTReturn rightOutput = isBST2(root->right);
    int maximum = max(root->data, max(leftOutput.maximum, rightOutput.maximum));
    int minimum = min(root->data, min(leftOutput.minimum, rightOutput.minimum));
    bool isBSTFinal = (root->data > leftOutput.maximum) && (root->data <= rightOutput.minimum) && (leftOutput.isBST) && (rightOutput.isBST);
    isBSTReturn output;
    output.maximum = maximum;
    output.minimum = minimum;
    output.isBST = isBSTFinal;
    return output;
}
int main() {
    BinaryTreeNode<int>* root = takeInput();
    isBSTReturn finalResult;
    finalResult = isBST2(root);
    cout << finalResult.isBST << endl;
    return 0;
}