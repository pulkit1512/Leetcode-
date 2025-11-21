class Solution {
public:
    int find(int x,int y,int m,int n ,vector<vector<int>>&dp,vector<vector<int>>&obstacleGrid){
        if(x>=m||y>=n) return 0;
        if(obstacleGrid[x][y]==1) return  0;
        if(x==m-1&&y==n-1) return 1;
        if(dp[x][y]!=-1) return dp[x][y];
        return dp[x][y]=find(x+1,y,m,n,dp,obstacleGrid)+find(x,y+1,m,n,dp,obstacleGrid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return find(0,0,m,n,dp,obstacleGrid);
    }
};