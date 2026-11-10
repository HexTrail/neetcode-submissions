class Solution {
public:
    int trap(vector<int>& height) {
        int maxWater = 0, start = 0, temp=0, n=height.size();
        for(int i=1;i<n;i++){
            if(height[i]<height[start]){
                temp+= height[start]- height[i];
            }
            else{
                maxWater += temp;
                temp = 0;
                start = i;
            }
        }
        start = n-1, temp=0;
        for(int i=n-1;i>=0;i--){
            if(height[i]<height[start]){
                temp+= height[start]- height[i];
            }
            else if(height[i]>height[start]){ //skipping the case height[i]= height[start], cause that is already covered in the first loop.
                maxWater += temp;
                temp = 0;
                start = i;
            }
        }
        return maxWater;
    }
};
