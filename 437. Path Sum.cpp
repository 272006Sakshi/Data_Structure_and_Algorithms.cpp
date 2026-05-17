class Solution {
public:
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(root->left==NULL && root->right==NULL){
            if(root->val==targetSum) return true;
        }
        bool leftSum = hasPathSum(root->left, targetSum-root->val);
        bool rightSum = hasPathSum(root->right, targetSum-root->val);
        if(leftSum) return true;
        else{
            return rightSum;
        }
    }
};
