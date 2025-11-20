class Solution {
public:
    int find(int stair,int n,vector<int>&cost,vector<int>&dp){
        if(stair>=n) return 0;
        if(dp[stair]!=-1) return dp[stair];
        dp[stair]=cost[stair]+min(find(stair+1,n,cost,dp),find(stair+2,n,cost,dp));
        return dp[stair];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+2,-1);
        return min(find(0,n,cost,dp),find(1,n,cost,dp));
    }
};