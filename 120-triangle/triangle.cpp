class Solution {
public:
    int find(int m,int x,int y,vector<vector<int>>& triangle,vector<vector<int>>&dp){
        if(x>=m) return 0;
        if(y>=triangle[x].size()) return 0;
        if(dp[x][y]!=INT_MAX) return dp[x][y];
        return dp[x][y]=triangle[x][y]+min(find(m,x+1,y,triangle,dp),find(m,x+1,y+1,triangle,dp));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
        vector<vector<int>>dp(m,vector<int>(n,INT_MAX));
        return find(m,0,0,triangle,dp);
    }
};