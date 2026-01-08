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
        
        // vector<vector<int>> res;
        // if (!root) return res;

        // queue<TreeNode*> q;
        // q.push(root);
        // bool leftToRight = true;

        // while (!q.empty()) {
        //     int n = q.size();
        //     vector<int> lev(n);

        //     for (int i = 0; i < n; i++) {
        //         TreeNode* node = q.front();
        //         q.pop();

        //         int index = leftToRight ? i : (n - 1 - i);
        //         lev[index] = node->val;

        //         if (node->left) q.push(node->left);
        //         if (node->right) q.push(node->right);
        //     }

        //     res.push_back(lev);
        //     leftToRight = !leftToRight; 
        // }

        // return res;
    }
};
