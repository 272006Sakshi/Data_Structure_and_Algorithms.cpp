// GFG Problem:- https://www.geeksforgeeks.org/problems/lemonade-change/1
class Solution {
  public:
    bool canServe(vector<int> &arr) {
        // code here
        int cnt_5 = 0;
        int cnt_10 = 0;
        
        for ( int i = 0; i < arr.size(); i++){
            //first we check for 5 
            if(arr[i] == 5) {
                cnt_5++;
            }
            
            else if(arr[i] == 10){
    
                if(cnt_5 > 0){
                    cnt_5--; //ek 5 ka sikka hata denge
                    cnt_10++; //10 wala sikka add kr denge
                }else{ //change nhi hai
                    return false;
                }
            } 
            else if(arr[i] == 20){
                
                if(cnt_5 > 0 && cnt_10 > 0){
                    cnt_5--; //10 ka sikka  de diya
                    cnt_10--; //phir 5 ka sikka de diya
                }else if(cnt_5 >= 3){ // 5 ke teen sikka se bhi kaam chal jayega
                    cnt_5 -= 3;
                }else{ //change nhi hai
                    return false;
                }
            } else{ 
                return false;
            }
        }
            return true;
            
    }
};
