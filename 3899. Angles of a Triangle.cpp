class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        double a = sides[0];
        double b = sides[1];
        double c = sides[2];
        if(a+b<=c || b+c<=a || a+c<=b){
            return {};
        }
        double A = acos((b*b + c*c - a*a)/(2*b*c));
        double B = acos((a*a + c*c - b*b)/(2*a*c));
        double C = acos((a*a + b*b - c*c)/(2*a*b));
        double degree = 180.0/M_PI;
        vector<double> angle = {A*degree, B*degree, C*degree};
        sort(angle.begin(), angle.end());
        return angle;
    }
};
