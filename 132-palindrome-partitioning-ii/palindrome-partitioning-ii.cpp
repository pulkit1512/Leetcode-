class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n);
        vector<vector<bool>> isPal(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            int minCuts = n - 1 - i; // Maximum cuts possible for substring s[i...n-1]
            
            for (int j = i; j < n; j++) {
                // Check if s[i...j] is a palindrome in O(1) time
                if (s[i] == s[j] && (j - i <= 1 || isPal[i + 1][j - 1])) {
                    isPal[i][j] = true;
                    
                    if (j == n - 1) {
                        minCuts = 0; // If the whole remaining string is a palindrome, 0 cuts needed
                    } else {
                        minCuts = min(minCuts, 1 + dp[j + 1]);
                    }
                }
            }
            dp[i] = minCuts;
        }
        return dp[0];
    }
};