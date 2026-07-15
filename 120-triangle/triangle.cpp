class Solution {
public:
    // int find(int m,int x,int y,vector<vector<int>>& triangle,vector<vector<int>>&dp){
    //     if(x>=m) return 0;
    //     if(y>=triangle[x].size()) return 0;
    //     if(dp[x][y]!=INT_MAX) return dp[x][y];
    //     return dp[x][y]=triangle[x][y]+min(find(m,x+1,y,triangle,dp),find(m,x+1,y+1,triangle,dp));
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,INT_MAX));
        dp[1][1]=triangle[0][0];
        for(int i=2;i<=m;i++){
            for(int j=1;j<=i;j++){
                dp[i][j]=triangle[i-1][j-1]+min(dp[i-1][j],dp[i-1][j-1]);
            }
        }
        int minTotal = INT_MAX;
        for (int j = 1; j <= m; j++) {
            minTotal = min(minTotal, dp[m][j]);
        }
        
        return minTotal;
    }
};