class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        int res = 0;
        sort(costs.begin(), costs.end());
        for(int i=0;i<n;i++){
            if(costs[i]<=coins){
                res++;
                coins-=costs[i];
            }
        }
        return res;
    }
};
