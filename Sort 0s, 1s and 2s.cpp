class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int n = arr.size();
        int cnt_0 = 0;
        int cnt_1 = 0; 
        int cnt_2 = 0;
        
        for(int i = 0; i<n; i++){
            if(arr[i] == 0) cnt_0++;
            else if(arr[i] == 1) cnt_1++;
            else cnt_2++;
        }
        
        for(int i = 0; i<cnt_0; i++){
            arr[i] = 0;
        }
        for(int i = cnt_0; i<cnt_0+cnt_1; i++){
            arr[i] = 1;
        }
        for(int i = cnt_0+cnt_1; i< cnt_0+cnt_1+cnt_2; i++){
            arr[i] = 2;
        }
    }
};
