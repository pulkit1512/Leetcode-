class Solution {
public:
    int maxProfit(int x, vector<int>& prices) {
        int n = prices.size();
         vector<vector<int>>dp(2, vector<int>(x + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= 1; j++) {
                for (int k = 1; k <= x; k++) {
                    int profit = INT_MIN;
                    if (j) {
                        profit =
                            max(-prices[i] + dp[0][k], dp[1][k]);
                    } else {
                        profit = max(prices[i] + dp[1][k - 1],
                                     dp[0][k]);
                    }
                    dp[j][k] = profit;
                }
            }
        }
        return dp[1][x];
    }
};