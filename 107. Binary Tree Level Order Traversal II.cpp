/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   void levelTraversal(TreeNode* root, vector<vector<int>> &res, int level){
    if(!root) return;
    if(level>=res.size()){
        res.push_back({});
    }
    res[level].push_back({root->val});
    levelTraversal(root->left, res, level+1);
    levelTraversal(root->right, res, level+1);
   }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        levelTraversal(root, res, 0);
        reverse(res.begin(), res.end());
        return res;
    }
};
