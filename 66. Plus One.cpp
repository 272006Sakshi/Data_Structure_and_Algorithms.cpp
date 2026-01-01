class Solution {
public:
//T.C: O(N), S.C: O(1)
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size()-1; i>=0; i--){
            if(i==digits.size()-1){
                digits[i]+=1;
            }
            if(digits[i] == 10){
                digits[i] = 0;
                if(i!=0){
                    digits[i-1]+=1;
                }
                else{
                    digits.push_back(0);
                    digits[i] = 1;
                } 

            }
            
        }
        return digits;
        // for(int i=digits.size()-1;i>=0;i--){
        //     if(digits[i]<9){
        //         digits[i]+=1;
        //         return digits;
        //     }
        //     digits[i] = 0;
        // }

        // digits.insert(digits.begin(),1);
        // return digits;
    }

        
};
