class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> count;

        for(char &ch:text){
            if(ch=='b' || ch=='a' || ch=='l' || ch=='o' || ch=='n'){
                count[ch]++;
            }
        }
        int b = count['b'], a=count['a'], l=count['l']/2, o=count['o']/2, n=count['n'];

        return min({b, a, l, o, n});
    }
};
