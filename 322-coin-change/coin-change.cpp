class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int>dp(amount+1,1e8);
            dp[0]=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]>j) dp[j]=dp[j];
                else{
                    dp[j]=min(1+dp[j-coins[i-1]],dp[j]);
                }
            }
        }
        if(dp[amount]==1e8) return -1;
        return dp[amount];
    }
};