class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) return true;

        int first = 0, second = 0;
        while (second < t.length()) {
            if (s[first] == t[second]) {
                first++;
                if (first == s.length()) return true;
            }
            second++;
        }
        return false;
    }
};
