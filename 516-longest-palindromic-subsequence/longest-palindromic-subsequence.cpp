class Solution {
public:
    int find(string s1,string s2){
        int n=s1.size();

        vector<int>dp(n+1,0);
        int prev,curr;
        for(int i=1;i<=n;i++){
            prev=0,curr=0;
            for(int j=1;j<=n;j++){
                prev=curr;
                curr=dp[j];
                if(s1[i-1]==s2[j-1]){
                    dp[j]=1+prev;
                }
                else dp[j]=max(dp[j],dp[j-1]);
            }
        }
        return dp[n];
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        string s1=s;
        reverse(s.begin(),s.end());
        return find(s1,s);
    }
};