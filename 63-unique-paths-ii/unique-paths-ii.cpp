class Solution {
public:
    // int find(int x,int y,int m,int n ,vector<vector<int>>&dp,vector<vector<int>>&obstacleGrid){
    //     if(x>=m||y>=n) return 0;
    //     if(obstacleGrid[x][y]==1) return  0;
    //     if(x==m-1&&y==n-1) return 1;
    //     if(dp[x][y]!=-1) return dp[x][y];
    //     return dp[x][y]=find(x+1,y,m,n,dp,obstacleGrid)+find(x,y+1,m,n,dp,obstacleGrid);
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1||obstacleGrid[m-1][n-1]==1) return 0;
        vector<int>dp(n+1,0);
        dp[1]=1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(i==1&&j==1) continue;
                if(obstacleGrid[i-1][j-1]==1) dp[j]=0;
                else{
                    dp[j]=dp[j]+dp[j-1];// dp[j] in space optimization is equivalent to the dp[i-1][j]
                }
                
            }
        }
        return dp[n];
    }
};