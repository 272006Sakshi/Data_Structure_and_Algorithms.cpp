class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int water = 0;
        // for(int i = 0; i<n; i++){
        //     int leftMax = 0, rightMax = 0;

        //     for(int j = 0; j<=i; j++){
        //         leftMax = max(leftMax, height[j]);
        //     }

        //     for(int j = i; j<n; j++){
        //         rightMax = max(rightMax, height[j]);
        //     }

        //     water += min(leftMax, rightMax) - height[i];

        // }
        int left = 0, right = n-1;
        int leftMx =0, rightMx = 0;

        while(left<right){
            if(height[left]<height[right]){
                if(height[left] >= leftMx){
                    leftMx = height[left];

                }
                else{
                    water += leftMx - height[left];
                }
                left++;
            }
            else{
                if(height[right] >= rightMx){
                    rightMx = height[right];
                }
                else{
                    water += rightMx - height[right];
                }
                right--;
            }
        }
        return water;


    }
};
