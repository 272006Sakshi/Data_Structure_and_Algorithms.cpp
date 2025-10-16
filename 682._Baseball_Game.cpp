class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> rec;
        for(string &op : operations){
            if(op == "C"){
                rec.pop_back();
            }
            else if(op == "D"){
                rec.push_back(2*rec.back());
            }
            else if(op == "+"){
                rec.push_back(rec[rec.size()-1]+rec[rec.size()-2]);
            }
            else{
                rec.push_back(stoi(op));
            }
        }
        int sum = 0;
        for(int i = 0; i<rec.size(); i++){
            sum+=rec[i];
        }
        return sum;
    }
};
