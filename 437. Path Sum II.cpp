class Solution {
public:
    vector<vector<int>> res;
    void pathNode(TreeNode* root, int sum, vector<int> arr, int targetSum){
        if(!root) return;
        sum+=root->val;
        arr.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            if(sum==targetSum){
                res.push_back(arr);
            }
            return;
        }
        pathNode(root->left, sum, arr, targetSum);
        pathNode(root->right, sum, arr, targetSum);

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum=0;
        vector<int> arr;
        pathNode(root, sum, arr, targetSum);
        return res;
    }
};
