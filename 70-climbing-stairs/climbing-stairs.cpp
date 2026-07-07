class Solution {
public:
    int helper(int stair,int n, vector<int>&dp){
        if(stair>n) return 0;
        if(stair==n) return 1;
        if(dp[stair]!=-1) return dp[stair];
        dp[stair]=helper(stair+1,n,dp)+helper(stair+2,n,dp);
        return dp[stair];
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return helper(0,n,dp);
    }
};