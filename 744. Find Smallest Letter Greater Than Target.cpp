class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = letters.size();
        
        for(int i = 0; i<l; i++){
            if(letters[i]>target){
                return letters[i];
            }
        }
        return letters[0];
    }
};
