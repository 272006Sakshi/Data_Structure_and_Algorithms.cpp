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
    int balanced(TreeNode* root, bool& ans){
      // t.c : O(N)
        if(!root){
            return 0;
        }
        int l = balanced(root->left, ans);
        int r = balanced(root->right, ans);
        if(abs(l-r)>1)ans=false;
        return max(l+1, r+1);

    }
    bool isBalanced(TreeNode* root) {
        bool ans= true;
        balanced(root, ans);
        return ans;
        
    }
};
