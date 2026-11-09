class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool isValid = true;
        unordered_set<int> s1, s2, s3, r, c;
        for(int i=0;i<9;i++){
            if(i%3==0){
                s1.clear();
                s2.clear();
                s3.clear();
            }
            r.clear();
            c.clear();
            for(int j=0;j<9;j++){
                char c1 = board[i][j];
                char c2 = board[j][i];
                if(c2!='.'){
                    if(c.contains(c2)) return false;
                    c.insert(c2);
                }
                if(c1=='.'){
                    continue;
                }
                if(r.contains(c1)) return false;
                r.insert(c1);
                if(j<3){
                    if(s1.contains(c1)) return false;
                    s1.insert(c1);
                }
                else if(j<6){
                    if(s2.contains(c1)) return false;
                    s2.insert(c1);
                }
                else if(j<9){
                    if(s3.contains(c1)) return false;
                    s3.insert(c1);
                }
            }
        }
        return true;       
    }
};
