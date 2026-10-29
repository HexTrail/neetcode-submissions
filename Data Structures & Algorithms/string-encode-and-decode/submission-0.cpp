class Solution {
public:

    string encode(vector<string>& strs) {
        string o="";
        for(auto s: strs){
            o+= to_string(s.length())+ "#"+s;
        }
        return o;
    }

    vector<string> decode(string s) {
        int i=0, len = 0;
        vector<string> res;
        while(i<s.length()){
            int j= i;
            while(s[j]!='#') j++;
            len = stoi(s.substr(i, j-i));
            res.emplace_back(s.substr(j+1, len));
            i = j+len+1; //j is #. so +1 for skipping # then +len for skipping through the length of the string. 

        }

        return res;
    }
};
