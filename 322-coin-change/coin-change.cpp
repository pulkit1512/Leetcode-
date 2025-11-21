class Solution {
public:
    int find(int index,int amount,vector<int>&coins,vector<vector<int>>&dp){
        if(amount==0) return 0 ;
        if(index<0) return 1e9;
        if(dp[index][amount]!=-1) return dp[index][amount];
        if(coins[index]>amount) return dp[index][amount]=find(index-1,amount,coins,dp);
        else{
            return dp[index][amount]=min(1+find(index,amount-coins[index],coins,dp),find(index-1,amount,coins,dp));
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans= find(n-1,amount,coins,dp);
        if(ans==1e9) return -1;
        return ans;
    }
};