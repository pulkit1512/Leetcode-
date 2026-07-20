class Solution {
public:
    int find(string word1,string word2){
        int n=word1.size();
        int m=word2.size();
        vector<int>dp(m+1,0);
        int prev,curr;
        for(int i=1;i<=n;i++){
            prev=0,curr=0;
            for(int j=1;j<=m;j++){
                prev=curr;
                curr=dp[j];
                if(word1[i-1]==word2[j-1]){
                    dp[j]=1+prev;
                }
                else dp[j]=max(dp[j],dp[j-1]);
            }
        }
        return dp[m];
    }
    int minInsertions(string s) {
        string s1=s;
        reverse(s.begin(),s.end());
        int lps=find(s1,s);
        return s.size()-lps;
    }
};