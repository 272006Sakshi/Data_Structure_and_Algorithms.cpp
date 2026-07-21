class Solution {
public:
    int res = 0;
    int solve(TreeNode* root){
        if(root==NULL) return INT_MIN;
        int leftMax = solve(root->left);
        int rightMax = solve(root->right);
        int maxSubtree = max({root->val, leftMax, rightMax});
        if(root->val==maxSubtree){
            res++;
        }
        return maxSubtree;
    }
    int countDominantNodes(TreeNode* root) {
        solve(root);
        return res;
    }
};
