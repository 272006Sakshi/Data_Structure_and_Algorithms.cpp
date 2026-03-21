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
    vector<TreeNode*> possibleBSTs(int st, int end){
        vector<TreeNode*> res;
        if(st>end){
            res.push_back(NULL);
            return res;
        }

        for(int i = st; i<=end; i++){
            vector<TreeNode*> leftSubtree = possibleBSTs(st, i-1);
            vector<TreeNode*> rightSubtree = possibleBSTs(i+1, end);
            
            // connect left & right subtree to ith root
            for(int j=0;j<leftSubtree.size();j++){
                for(int k=0;k<rightSubtree.size();k++){
                    TreeNode* rootVal = new TreeNode(i);
                    rootVal->left = leftSubtree[j];
                    rootVal->right = rightSubtree[k];
                    res.push_back(rootVal);
                }
            }

        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return possibleBSTs(1, n);
    }
};
