class Solution {
public:
    void levelSum(TreeNode* root, int level, vector<int> &sum) {
        if (!root) return;
        if (level > sum.size()) sum.push_back(0);
        sum[level - 1] += root->val;
        levelSum(root->left, level + 1, sum);
        levelSum(root->right, level + 1, sum);
    }
    int maxLevelSum(TreeNode* root) {
        vector<int> sum;
        levelSum(root, 1, sum);
        int maxi = INT_MIN;
        int ans = 1;
        for (int i = 0; i < sum.size(); i++) {
            if (sum[i] > maxi) {
                maxi = sum[i];
                ans = i + 1;
            }}
        return ans;
    }
};
