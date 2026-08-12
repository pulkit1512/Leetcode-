class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>dp(n, vector<int>(m, 1e9));

        for (int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if (mat[i][j]) {
                    int top = (i>0) ? dp[i-1][j] : 1e9;
                    int left = (j>0) ? dp[i][j-1]: 1e9;
                    dp[i][j] = min(top, left) + 1;
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        for (int i = n-1;i>=0;i--) {
            for(int j = m-1;j>=0;j--) {
                if (mat[i][j]) {
                    int bottom = (i< n-1) ? dp[i+1][j] : 1e9;
                    int right = (j < m-1) ? dp[i][j+1] : 1e9;

                    dp[i][j] = min(dp[i][j], min(bottom, right) + 1); 
                }
            }
        }

        return dp;
    }
};