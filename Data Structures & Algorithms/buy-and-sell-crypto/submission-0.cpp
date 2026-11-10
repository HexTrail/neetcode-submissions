class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int start = 0, next = -1, maxP = 0;
        for(int i=0;i<prices.size()-1;i++){
            auto mx = max_element(prices.begin()+i, prices.end());
            if(*mx>prices[i]){
                int p = *mx-prices[i];
                if(p>maxP) maxP = p;
            }
        }
        return maxP;
    }
};
