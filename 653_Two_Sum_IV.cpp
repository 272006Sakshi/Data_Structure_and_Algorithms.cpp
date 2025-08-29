class Solution {
public:
    void inorder(TreeNode* root, vector<int> &vec){
        if(!root) return;
        inorder(root->left, vec);
        vec.push_back(root->val);
        inorder(root->right, vec);

    }
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        vector<int> vec;
        inorder(root, vec);

        int left = 0, right = vec.size()-1;
        int sum = 0;
        while(left<right){
            sum = vec[left]+vec[right];
            if(sum == k) return true;
            else if(sum<k) left++;
            else{
                right--;
            }
        }
        return false;
        
    }
};
