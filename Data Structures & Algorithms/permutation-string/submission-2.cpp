class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> mp;
        for(auto ch: s1){
            mp[ch]++;
        }
        unordered_map<char, int> mp2 = mp;
        for(auto ch: s2){
            if(mp2[ch]){
                mp2[ch]--;
            }
            else{
                mp2.clear();
                mp2 = mp;
            }

            int flag = 1;
            for(auto [key, val]: mp2){
                if(val!=0){
                    flag = 0;
                    break;
                }
            }

            if(flag){
                return true;
            }
        }
        mp2.clear();
        mp2 = mp;
        for(int i=s2.length()-1;i>=0;i--){
            char ch = s2[i];
            if(mp2[ch]){
                mp2[ch]--;
            }
            else{
                mp2.clear();
                mp2 = mp;
            }

            int flag = 1;
            for(auto [key, val]: mp2){
                if(val!=0){
                    flag = 0;
                    break;
                }
            }

            if(flag){
                return true;
            }
        }
        return false;
    }
};
