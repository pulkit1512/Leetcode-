class Solution {
public:
    int find(int i,int amount,vector<int>&coins,int n,vector<vector<int>>&dp){
        if(amount==0) return 1;
        if(amount<0||i>=n) return 0;
        if(dp[i][amount]!=-1) return dp[i][amount];
        dp[i][amount]=find(i,amount-coins[i],coins,n,dp)+find(i+1,amount,coins,n,dp);
        return dp[i][amount];
    }
    int change(int amount, vector<int>& coins) {
        int n =coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return find(0,amount,coins,n,dp);
    }
};