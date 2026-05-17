class Solution {
public:
    int cnt = 0;
    void cntPath(TreeNode* root, long long sum, int targetSum){
        if(root == NULL){
            return;
        }
        sum+=root->val;
        if(sum==targetSum) cnt++;
        
        cntPath(root->left, sum, targetSum);
        cntPath(root->right, sum, targetSum);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        cntPath(root, 0, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return cnt;
    }
};
