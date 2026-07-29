class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res={};
        sort(nums.begin(), nums.end());
        for(int i=0;i<(int)nums.size()-2;i++){
            if (i > 0 && nums[i] == nums[i-1]) continue; //if the new number is same as last one, skip.
            int j=i+1, k=nums.size()-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum==0){
                    res.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j+1]) j++; //If new numbers are same, then skip.
                    while (j < k && nums[k] == nums[k-1]) k--;
                    j++; k--; //the above loops end with us on the last repeated same number as the current one. so now move forward one step.
                }
                else if(sum>0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return res;
    }
};
