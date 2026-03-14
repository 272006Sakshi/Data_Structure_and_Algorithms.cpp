class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        vector<int> res;
        if(root == NULL) return res;
        
        unordered_map<int, int> mp;  
        queue<pair<Node*, int>> q;
        
        int minHD = 0, maxHD = 0;
        
        q.push({root, 0});
        
        while(!q.empty()){
            
            auto front = q.front();
            q.pop();
            
            Node* curr = front.first;
            int hd = front.second;
            
            if(mp.find(hd) == mp.end()){
                mp[hd] = curr->data;
            }
            
            minHD = min(minHD, hd);
            maxHD = max(maxHD, hd);
            
            if(curr->left)
                q.push({curr->left, hd - 1});
                
            if(curr->right)
                q.push({curr->right, hd + 1});
        }
        
        // Traverse from leftmost HD to rightmost
        for(int i = minHD; i <= maxHD; i++){
            res.push_back(mp[i]);
        }
        
        return res;
    }
};
