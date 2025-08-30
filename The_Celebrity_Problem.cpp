class Solution {
  public:
// T.C : O(N)
// S.C : O(N)
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        stack<int> st;
        for(int i = 0; i<n; i++){
            st.push(i);
            
        }
        while(st.size()>1){
            int i = st.top();
            st.pop();
            
            int j = st.top();
            st.pop();
            
            if(mat[i][j]==0){
                st.push(i);
            }
            else{
                st.push(j);
            }
        }
        
        int celeb = st.top();
        for(int i = 0; i<n; i++){
            if((i!=celeb) && (mat[i][celeb] == 0 || mat[celeb][i] == 1)){
                return -1;
            }
        }
        return celeb;
    }
};
