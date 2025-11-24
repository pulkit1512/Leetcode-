class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; i++) {
            string s = to_string(i);
            bool check = true;
            for (int j = 0; j < s.length(); j++) {
                int digit = s[j] - '0';
                if (digit == 0 || i % digit != 0) {
                    check = false;
                    break;
                }
            }
            if (check) ans.push_back(i);
        }
        return ans;
    }
};
