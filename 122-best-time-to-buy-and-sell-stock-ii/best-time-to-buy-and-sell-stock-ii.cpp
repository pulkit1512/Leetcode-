class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        vector<int>dp(2,0);
        dp[1]=INT_MIN;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=1;j++){
                int profit=0;
                if(j){
                    //buyinh it 
                    profit=max(-prices[i-1]+dp[0],dp[1]);
                }
                else profit=max(prices[i-1]+dp[1],dp[0]);
                dp[j]=profit;
            }
        }
        return dp[0];
    }
};