class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<int> dp(m + 1, 0);
        for (int i = 1; i <= n; i++) {
            vector<int> dp2(m + 1, 0);
            for (int j = 1; j <=m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp2[j] = 1 + dp[j - 1];
                } else {
                    dp2[j] = max(dp[j], dp2[j - 1]);
                }
            }
            dp = dp2;
        }
        return dp[m];
    }
};