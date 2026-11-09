class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long product = 1;
        int n = nums.size(), zeroFlag = 0;
        vector<int> output;
        for(auto e: nums){
            if(e==0){
                zeroFlag +=1;
                continue;
            }
            product *= e;
        }
        for(int i=0;i<n;i++){
            if(zeroFlag==1 && nums[i]==0){
                output.emplace_back(product);
            }
            else if(zeroFlag==0 && nums[i]!=0){
                output.emplace_back(product/nums[i]);
            }
            else{
                output.emplace_back(0);
            }
        }
        return output;
    }
};
