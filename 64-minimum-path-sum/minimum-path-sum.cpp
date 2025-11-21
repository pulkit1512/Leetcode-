class Solution {
public:
    int find(int x,int y,int m,int n,vector<vector<int>>&dp,vector<vector<int>>&grid){
        if(x>=m||y>=n) return INT_MAX;
        if(x==m-1&&y==n-1) return grid[x][y];
        if(dp[x][y]!=-1) return dp[x][y];
        else{
        return dp[x][y]=grid[x][y]+min(find(x+1,y,m,n,dp,grid),find(x,y+1,m,n,dp,grid));
        }
    }
    int minPathSum(vector<vector<int>>& grid) {
          int m=grid.size();
          int n=grid[0].size();
          vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
          int z=find(0,0,m,n,dp,grid);
          return z;
    }
};