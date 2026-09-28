class Solution {
public:
    int lengthOfLastWord(string s) {
        bool temp=false;
        string ans="";
        for(int i=s.size()-1;i>=0;i--){
            while(i>=0&&s[i]==' ') i--;
            while(i>=0&&s[i]!=' '){
                ans+=s[i];
                i--;
            }
            break;
        }
        reverse(ans.begin(),ans.end());
        return ans.length();
    }
};