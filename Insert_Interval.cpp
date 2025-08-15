class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // code here
        int ind = 0;
        int n = intervals.size();
        vector<vector<int>> ans;
        while(ind<n){
            if(intervals[ind][1]<newInterval[0]) ans.push_back(intervals[ind]);
            
            else if(intervals[ind][0] > newInterval[1]){
                // intervals.insert(intervals.begin()+ind, newInterval);
                // return intervals;
                break;
                
            }
            else{
                newInterval[0] = min(newInterval[0], intervals[ind][0]);
                newInterval[1] = max(newInterval[1], intervals[ind][1]);
                // intervals.erase(intervals.begin()+ind);
                
            }
            ind++;
        
        }
        ans.push_back(newInterval);
        while(ind<n){
            ans.push_back(intervals[ind]);
            ind++;
        }
        return ans;
        
    }
};
