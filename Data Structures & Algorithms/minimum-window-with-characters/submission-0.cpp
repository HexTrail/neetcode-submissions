class Solution {
   public:
    string minWindow(string s, string t) {
        if (t.length() > s.length()) return "";
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        for(auto ch: t) m1[ch]++;
        int matches = 0, l=0, startI = -1, minL = INT_MAX;
        for(int r=0;r<s.length();r++){
            char c = s[r];
            m2[c]++;
            if(m1.count(c)&& m2[c]==m1[c]) matches++;
            while(matches==m1.size()){
                if((r-l+1)<minL){
                    startI = l;
                    minL = r-l+1;
                }
                char c = s[l];
                m2[c]--;
                l++;
                if(m1.count(c) && m2[c]==m1[c]-1) matches--;
            }
        }
        if(startI!=-1) return s.substr(startI, minL);
        return "";
    }
};
