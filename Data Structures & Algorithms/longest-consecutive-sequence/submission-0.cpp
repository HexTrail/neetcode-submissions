class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size()==0) return 0;
        int maxL=1, tempLen=1;
        for(int i=1;i<nums.size(); i++){
            if(nums[i] == nums[i-1]+1) tempLen++;
            else if(nums[i]==nums[i-1]) continue;
            else tempLen = 1;
            if(tempLen>maxL) maxL = tempLen;
        }
        return maxL;
    }
};
