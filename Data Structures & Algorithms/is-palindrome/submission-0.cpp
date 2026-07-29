class Solution {
public:
    bool isPalindrome(string s) {
        int i=0, j=s.length() -1;
        while(i<j){
            while(i<j && !isalnum(s[i])){ //use while to skip all alphanumeric characters, otherwise if the next char is also aphanumeric, the comparison using if later will fail again.
                i++;
            }
            while(i<j && !isalnum(s[j])){
                j--;
            }
            if(tolower(s[i])!=tolower(s[j])){
                return false;
            }
            else{
            i++;
            j--;

            }
        }
        return true;
    }
};
