class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size(), m = *max_element(piles.begin(), piles.end());
        if(n==h) return m;
        sort(piles.begin(), piles.end());
        int l=1, r=m, curMin = INT_MAX; //we take l as 1 and r as m-1 cause these l and r are for bounding of k  and k can only range from 1 to m;
        while(l<=r){
            int k = (l+r)/2;
            int hTemp = 0;
            for(int j=n-1;j>=0;j--){
                hTemp += (piles[j] +k-1)/k; //integer arithmetic way to get upper bound after dividing by k. +k to increase the quotient by 1 and -1 to avoid increasing by when the the number is exactly divisible by k with zero remainder.
                if(hTemp> h) break;
            }
            if(hTemp<=h){
                //we have a match but don't know if we have minimum value of k for that. so set this k in curMin and check for lower k values.
                curMin = k;
                r = k-1;
            }
            else l = k+1;
        }
        return curMin;
    }
};
