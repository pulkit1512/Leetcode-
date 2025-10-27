class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0;
        string str="";
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==' '){
                if(ans!=0){
                    return ans;
                }
            }
            else if(s[i]!=' '){
                ans++;
            }
        }
        if(ans!=0) return ans;
        return 0;
    }
};