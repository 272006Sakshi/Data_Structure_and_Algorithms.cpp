/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    struct Info {
        bool isBST;
        int size;
        int minVal;
        int maxVal;
    };

    int maxSize = 0;

    Info solve(Node* root) {

        // Base case
        if (root == NULL) {
            return {true, 0, INT_MAX, INT_MIN};
        }

        // Postorder
        Info left = solve(root->left);
        Info right = solve(root->right);

        Info curr;

        
        if (left.isBST && right.isBST &&
            root->data > left.maxVal &&
            root->data < right.minVal) {

            curr.isBST = true;
            curr.size = left.size + right.size + 1;
            curr.minVal = min(root->data, left.minVal);
            curr.maxVal = max(root->data, right.maxVal);

            maxSize = max(maxSize, curr.size);
        }
        else {
            curr.isBST = false;
            curr.size = 0;     
            curr.minVal = INT_MIN;
            curr.maxVal = INT_MAX;
        }

        return curr;
    }
    int largestBst(Node *root) {
        // Your code here
        solve(root);
        return maxSize;
    }
};
