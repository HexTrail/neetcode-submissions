class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0, n = prices.size(), curMax = n-1;
        for(int i=n-2;i>=0;i--){
            if(prices[i]>prices[curMax]) curMax = i;
            else{
                int p = prices[curMax] - prices[i];
                if(p>maxP) maxP = p;
            }
        }
        return maxP;
    }
};
