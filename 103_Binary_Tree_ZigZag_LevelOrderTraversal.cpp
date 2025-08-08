class Solution {
public:
    // tc = O(N)
    // SC = O(N)
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>> res;
        if (!root) return res;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int n = q.size();
            vector<int> lev(n);

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                int index = leftToRight ? i : (n - 1 - i);
                level[index] = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            res.push_back(level);
            leftToRight = !leftToRight; 
        }

        return res;
    }
};
