class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<double>dp(m + 1, 0);
        dp[0] = 1;
        double prev,curr;
        for (int i = 1; i <= n; i++) {
            prev=0,curr=0;
            for (int j = 1; j <= m; j++) {
                if(j==1) prev=1;
                else prev=curr;
                curr=dp[j];
                if (s[i - 1] == t[j - 1]) {
                    dp[j] = prev + dp[j];
                }
                else{
                    dp[j]=dp[j];
                }
            }
        }
        return (int)dp[m];
    }
};