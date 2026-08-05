class Solution {
public:
    bool com(string s1, string s2) {
        if (s1.size() == s2.size() + 1) {

            int first = 0;
            int second = 0;
            while (first != s1.size()) {
                if (second != s2.size() && s1[first] == s2[second]) {
                    first++;
                    second++;
                } else {
                    first++;
                }
            }
            if (first == s1.size() && second == s2.size())
            return true;
        }
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        vector<int> dp(n, 1);
        int maxi = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (com(words[i], words[j]) && dp[j] + 1 > dp[i]) {
                    dp[i] = 1 + dp[j];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};