class Solution {
public:
    int  helper(vector<vector<int>>& triangle,int x,int y,int n,vector<vector<int>>&dp){
        if(x>=n) return 0;
        if(y>=triangle[x].size()) return 0;

        if(dp[x][y]!=-1) return dp[x][y];

        return dp[x][y]=triangle[x][y]+min(helper(triangle,x+1,y,n,dp),helper(triangle,x+1,y+1,n,dp));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<vector<long long>>dp(n+1,vector<long long>(m+1,INT_MAX));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=triangle[i-1].size();j++){
                if(i==1&&j==1){
                    dp[i][j]=triangle[i-1][j-1];
                    continue;
                }
                dp[i][j]=triangle[i-1][j-1]+min(dp[i-1][j],dp[i-1][j-1]);
            }
        }
        long long  ans=INT_MAX;
        for(int i=0;i<dp[n].size();i++){
            ans=min(ans,dp[n][i]);
        }
        return ans;
    }
};