class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>dp(n+1,INT_MAX);
        dp[1]=grid[0][0];
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(i==1&&j==1) continue ;
                dp[j]=grid[i-1][j-1]+min(dp[j],dp[j-1]);
            }
        }
        return dp[n];
    }
};