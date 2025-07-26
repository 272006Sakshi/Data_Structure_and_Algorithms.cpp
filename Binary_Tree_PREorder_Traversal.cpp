class Solution {
public:

    void preO_trav(TreeNode* root, vector<int>& res){
        if(root == NULL) return;
        res.push_back(root->val);
        preO_trav(root->left, res);
        preO_trav(root->right, res);
        
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preO_trav(root, res);
        return res;
    }
};
