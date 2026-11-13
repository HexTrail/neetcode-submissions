class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int maxL = 0, l = 0, maxf=0;

        for(int r=0;r<s.length();r++){
            count[s[r]]++;
            maxf = max(count[s[r]], maxf);

            while((r-l+1)-maxf >k){
                count[s[l]]--;
                l++;
            }
            maxL = max(r-l+1, maxL);
        }
        return maxL;
    }
};
