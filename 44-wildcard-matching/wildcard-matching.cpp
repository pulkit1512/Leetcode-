class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<int>dp(m + 1, 0);
        vector<int>dp2(m+1,0);
        dp[0] = 1;
        // dp2[0]=1;
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*') {
                dp[j] = dp[j - 1];
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp2[j] = dp[j - 1];
                } 
                else if (p[j - 1] == '*') {
                    dp2[j] = dp2[j - 1] || dp[j];
                } 
                else {
                    dp2[j] = false;
                }
            }
            dp=dp2;
        }
        
        return dp[m];
    }
};