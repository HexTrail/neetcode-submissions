class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0, r= nums.size()-1, min=INT_MAX;
        if(nums[l]<nums[r]) return nums[l]; //it means the array is sorted. 

        //array is rotated. so min element is at any position starting from 1 to n-1, but not at 0 atleast. It means nums[0] is always greater than nums[n-1].
        while(l<=r){
            int m = (l+r)/2;
            if(nums[m]<min) min = nums[m];
            if(m==l || nums[m-1]>nums[r]) l = m+1;
            else r = m-1;
        }
        return min;
    }
};
