class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        map<int, vector<int>, greater<int>> mp2; //second map to store freq -> element in descending order (from highest frequency).
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto [key, val]: mp){
            mp2[val].emplace_back(key);
        }
        vector<int> res; 
        int count =0;
        for(auto [key, val]: mp2){
            for(auto e: val){
                count++;
                res.emplace_back(e);
                if(count>=k) return res; 
            }
        }
        return res;
    }
};
