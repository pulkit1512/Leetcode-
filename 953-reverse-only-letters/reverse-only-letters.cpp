class Solution {
public:

    string reverseOnlyLetters(string s) {
        int start = 0, end = s.length() - 1;
        while (start <= end) {
            if(isalpha(s[start])&&isalpha(s[end])){
                swap(s[start],s[end]);
                start++;
                end--;
            }
            else if(!isalpha(s[start])&&isalpha(s[end])){
                start++;
            }
            else if(isalpha(s[start])&&!isalpha(s[end])){
                end--;
            }
            else{
                start++;
                end--;
            }
        }
        return s; 
    }
};