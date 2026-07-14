class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        for (int i = 0; i <= m; i++) {
            dp[i][0] = INT_MAX;
        }
        for (int i = 0; i <= n; i++) {
            dp[0][i] = INT_MAX;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 && j == 1) {
                    dp[i][j] = grid[i - 1][j - 1];
                    continue;
                }
                dp[i][j] = grid[i - 1][j - 1] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};