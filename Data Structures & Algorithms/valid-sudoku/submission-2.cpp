class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool isValid = true;
        int rows = board.size(), cols = board[0].size();
        //check for duplicates in each row
        for(auto row: board){
            unordered_set<int> s;
            for (auto col: row){
                if(col=='.') continue;
                if(s.contains(col)){
                    return false;
                }
                s.insert(col);
            }
        }
        //check for duplicates in each column
        for(int i=0;i<rows;i++){
            unordered_set<int> s;
            for(int j=0;j<cols;j++){
                char c = board[j][i];
                if(c=='.') continue;
                if(s.contains(c)){
                    return false;
                }
                s.insert(c);
            }
        }

        //check for duplicates in each box group (3 groups at a time)
        unordered_set<int> s1;
        unordered_set<int> s2;
        unordered_set<int> s3;
        for(int i=0;i<rows;i++){
            if(i%3==0){
                s1.clear();
                s2.clear();
                s3.clear();
            }
            for(int j=0;j<cols;j++){
                char c = board[i][j];
                if(c=='.'){
                    continue;
                }
                if(j<3){
                    if(s1.contains(c)) return false;
                    s1.insert(c);
                }
                else if(j<6){
                    if(s2.contains(c)) return false;
                    s2.insert(c);
                }
                else if(j<9){
                    if(s3.contains(c)) return false;
                    s3.insert(c);

                }

            }
        }
        return true;       
    }
};
