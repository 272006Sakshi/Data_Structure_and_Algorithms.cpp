/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
   int maxS = INT_MIN;
   int findSum(Node *tree){
       if(!tree) return 0;
       
       int left = max(findSum(tree->left), 0);
       int right = max(findSum(tree->right), 0);
       
       int sum = tree->data + left + right;
       maxS = max(maxS, sum);
       
       return tree->data + max(left, right);
   }
    int findMaxSum(Node *root) {
        // code here
        
        findSum(root);
        return maxS;
        
    }
};
