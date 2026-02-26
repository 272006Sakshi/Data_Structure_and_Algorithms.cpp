class Solution {
public:
    int helper(TreeNode* root, int num){
        if(!root) return 0;
        num = (2*num)+root->val;
        if(root->left == NULL && root->right==NULL) return num; 
        return helper(root->left, num)+helper(root->right, num);
    }
    int sumRootToLeaf(TreeNode* root) {
        return helper(root, 0);
    }
};
