class Solution {
public:
// t.c : O(n) 
// Approach : inorder traversal.
// use  two pointers after inorder traversal.
// Left pointer at beginning, right pointer at end.
// sum = vec[left]+vec[right].
// If sum equal to k → return true.
// If sum is too small → move left++
// If sum is too big → move right--

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

