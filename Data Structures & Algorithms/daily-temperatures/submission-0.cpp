class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n= temperatures.size();
        vector<int> res(n);
        for(int i=n-1;i>=0;i--){
            if(i==n-1) res[i] = 0;
            else{
                if(temperatures[i+1]> temperatures[i]) res[i] = 1;
                else if(res[i+1]==0) res[i] = 0;
                else{
                    for(int j=i+1;j<n;j++){
                        int nextI = j+ res[j];
                        if(nextI< n && temperatures[nextI]> temperatures[i]){
                            res[i] = res[j] +j-i;
                            break;
                        }
                    }
                }
            }
        }
        return res;
    }
};
