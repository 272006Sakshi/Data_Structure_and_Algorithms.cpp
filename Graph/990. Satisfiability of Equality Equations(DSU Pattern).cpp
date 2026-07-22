class Solution {
public:
  // T.C: O(n) , n = size of equations 
// S.C: O(26) ~ O(1)
    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(x==parent[x]){
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y){
      int x_par = find(x);
      int y_par = find(y);
      if(x_par == y_par){
          return;
      }
      else if(rank[x_par]>rank[y_par]){
          parent[y_par] = x_par;
      }
      else if(rank[x_par]<rank[y_par]){
          parent[x_par] = y_par;
      }
      else{
          parent[y_par] = x_par;
          rank[y_par]++;
      }
    }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26, 0);

        for(int i=0; i<26;i++){
            parent[i]=i;
        }

        // if "==" then we find union of both char
        for(string &str :equations){
            if(str[1] == '='){
                Union(str[0]-'a', str[3]-'a');
            }
        }
        // if "!=" then we find parent of both char. if parents are same then we'll return false;
        for(string &str1:equations){
            if(str1[1] == '!'){
                int first_charPar = find(str1[0]-'a');
                int last_charPar = find(str1[3]-'a');
                if(first_charPar == last_charPar){
                    return false;
                }
            }
            
        }
        return true;
    }
};
