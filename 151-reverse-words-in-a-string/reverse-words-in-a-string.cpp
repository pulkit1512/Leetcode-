class Solution {
public:
    string reverseWords(string s) {
        vector<string> ans;
        string str = "", answer = "";

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (!str.empty()) {
                    ans.push_back(str);
                    str = "";
                }
            } else {
                str.push_back(s[i]);
            }
        }

        if (!str.empty()) {
            ans.push_back(str);
        }

        reverse(ans.begin(), ans.end());

        for (int i = 0; i < ans.size(); i++) {
            answer += ans[i];
            if (i != ans.size() - 1) {
                answer += " ";
            }
        }

        return answer;
    }
};
