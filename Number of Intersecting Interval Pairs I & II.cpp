class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        long cnt = 0;
        // sort(intervals.begin(), intervals.end());
        // for(int i=0;i<n;i++){
        //     int st = intervals[i][0];
        //     int end = intervals[i][1];
        //     for(int j=i+1;j<n;j++){
        //         if(end>=intervals[j][0]){
        //             cnt++;
        //         }
        //     }
        // }
        // return cnt;

        
        vector<int> st, end;
        for(int i=0;i<n;i++){
            st.push_back(intervals[i][0]);
            end.push_back(intervals[i][1]);
        }
        sort(st.begin(), st.end());
        sort(end.begin(), end.end());
        int j=0;
        for(int i=0;i<n;i++){
            while(j<n && end[j]<st[i]){
                j++;
            }
            cnt+=i-j;
        }
        return cnt;
    }
};
