class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        vector<int> freq(256, 0);
        int first = 0;
        int second = 0;
        int n = s.size();
        while (first < n && second < n) {
            if (freq[s[second]] > 0) {
                while (first < n && s[first] != s[second]) {
                    freq[s[first]]--;
                    first++;
                }
                freq[s[first]]--;
                first++;
            }

            freq[s[second]]++;
            ans = max(ans, second - first + 1);
            second++;
        }
        return ans;
    }
};