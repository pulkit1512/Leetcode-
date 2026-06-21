class Solution {
public:
    string helper(string s) {
        string s1 = "";
        int i = 0;
        while (i < s.size()) {
            int count = 1;
            while (i + 1 < s.size() && s[i] == s[i + 1]) {
                count++;
                i++;
            }
            s1 += to_string(count);
            s1 += s[i];
            i++;
        }
        return s1;
    }

    string countAndSay(int n) {
        string s = "1";
        for (int i = 2; i <= n; i++) {
            s = helper(s);
        }
        return s;
    }
};
