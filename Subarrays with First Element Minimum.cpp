class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        // code here
       
        int n = arr.size();
      // Brute Force: O(n^2);
        // int res = 0;
        // for(int i = 0;i<n; i++){
        //     for(int j = i;j<n;j++){
        //         if(arr[j]>=arr[i]){
        //             res++;
        //         }
        //         else{
        //             break;
        //         }
        //     }
            
        // }
        // return res;

      // Approach 2: Using stack  --> O(n)
        stack<int> st;
        int res = 0; 
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                res+=n-i;
            }
            else{
                res+=st.top()-i;
            }
            st.push(i);
        }
        return res;
        
    }
};
