class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        if(s.length()==0) return 0;
        int maxL=0, temp = 0, start = 0; //start marks the start of the current window. 
        for(int i=0;i<s.length();i++){
            char c = s[i];
            temp++;
            if(mp.count(c)!=0 && mp[c]>=start){ //making sure that the so called repeated character was last repeated within the current window and only when we would subtract the length of that substring. 
                temp = i - mp[c];
                start = mp[c]+1;
            }
            mp[c] = i; //store position of character. not index so that the if condition doesn't skip when the repeat character was encountered at index 0 (meaniing mp[c]==0)
            if(temp>maxL) maxL = temp;
        }
        return maxL;
    }
};
