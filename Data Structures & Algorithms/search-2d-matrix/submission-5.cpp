class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i=0;i<m;i++){
            // if(matrix[i][0]>target) return false;
            // if(target==matrix[i][n-1]) return true;
            if(target <= matrix[i][n-1]){
                int l = 0, r = n-1;
                while(l<=r){
                    int mid = (l+r)/2;
                    if(matrix[i][mid]==target) return true;
                    else if(matrix[i][mid]<target) l = mid+1;
                    else r = mid-1;
                }
            }
            // else if(target > matrix[i][n-1]) continue;
        }
        return false;
    }
};
