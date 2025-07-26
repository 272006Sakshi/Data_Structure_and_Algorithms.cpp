class Solution {
public:
  // T.C : O(N)
    void solve(TreeNode* root, vector<int> &res){
        if(root == NULL) return;
        solve(root->left, res);  // LEFT NODE
        res.push_back(root->val);  // ROOT NODE
        solve(root->right, res);   // RIGHT NODE
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        
        solve(root, res);
        return res;
    }
};
