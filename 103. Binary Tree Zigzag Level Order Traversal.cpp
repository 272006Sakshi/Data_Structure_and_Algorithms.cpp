class Solution {
public:
// Approach: 
//   Input: root = [3,9,20,null,null,15,7]
//   Output: [[3],[20,9],[15,7]]
// level-> even position: right to left
// level-> odd position: left to right

//  T.C: O(n), S.C: O(n)
    void levelArray(TreeNode* root, vector<vector<int>> &res, int level){
        if(!root) return;
        if(res.size()==level){
            res.push_back({});
        }
        if(level%2==0){
            res[level].push_back(root->val);
        }
        else{
            res[level].insert(res[level].begin(), root->val);
        }
        levelArray(root->left, res, level+1);
        levelArray(root->right, res, level+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        levelArray(root, res, 0);
        return res;
    }
};
