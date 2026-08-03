class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){  // Fixed: start j from 1
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];    
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        int lcs = dp[n][m];

        string s(n + m - lcs, '0');

        int i = n, j = m;
        int index = n + m - lcs - 1;
        while(i > 0 && j > 0){
            if(str1[i-1] == str2[j-1]){
                s[index] = str1[i-1];
                index--;
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                s[index] = str1[i-1]; 
                index--;
                i--;
            }
            else{
                s[index] = str2[j-1]; 
                index--;
                j--;
            }
        }
        while(i > 0){
            s[index] = str1[i-1];
            index--;
            i--;
        }
        while(j > 0){
            s[index] = str2[j-1];
            index--;
            j--;
        }
        return s;
    }
};