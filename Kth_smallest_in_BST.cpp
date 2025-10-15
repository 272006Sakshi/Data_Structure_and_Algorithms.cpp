/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  void inorder(Node *root, vector<int> &res){
      if(!root) return;
      inorder(root->left, res);
      res.push_back(root->data);
      inorder(root->right, res);
  }
    int kthSmallest(Node *root, int k) {
        // code here
        vector<int> res;
        inorder(root, res);
        if(k>res.size()) return -1;
        return res[k-1];
    }
};
