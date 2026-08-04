class Solution {
public:
    bool find(const string& s, const string& p, int i, int j,vector<vector<int>>&dp) {
        if (i == 0 && j == 0) return true;
        if (j == 0) return false;
        if (i == 0) {
            for (int k = 0; k < j; k++) {
                if (p[k] != '*') return false;
            }
            return true;
        }
        if(dp[i-1][j-1]!=-1) return dp[i-1][j-1];
        
        if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
            return dp[i-1][j-1]= find(s, p, i - 1, j - 1,dp);
        }
        if (p[j - 1] == '*') {
            return dp[i-1][j-1]=find(s, p, i, j - 1,dp) || find(s, p, i - 1, j,dp);
        }
        return dp[i-1][j-1]= false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return find(s, p, n, m,dp);
    }
};