class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        int dist = INT_MAX;
        for(int i=0;i<n;i++){
            if(words[i]==target){
                int nxt_dist = abs(i-startIndex);
                int prev_dist = n-nxt_dist;
                dist = min(dist, min(nxt_dist, prev_dist));
            }
        }
        if(dist!=INT_MAX) return dist;
        return -1;
    }
};
