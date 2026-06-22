class Solution {
public:
    void helper(string s, int i, bool& sign, int& ans,bool&temp2,bool&temp3) {
        if (i >= s.size())
            return;
        if (s[i] == ' '&&!temp2&&!temp3) {
            helper(s, i + 1, sign, ans,temp2,temp3);
        }
        if (s[i] == '-'&&!temp2&&!temp3) {
            sign = false;
            temp3=true;
            helper(s, i + 1, sign, ans,temp2,temp3);
        }
        if (s[i] == '+'&&!temp2&&!temp3) {
            temp3=true;
            sign = true;
            helper(s, i + 1, sign, ans,temp2,temp3);
        }
        if (isdigit(s[i])) {
            int temp = s[i] - '0';
            temp2=true;
            if (ans > (INT_MAX - temp) / 10) {
                sign ? ans = INT_MAX : ans = INT_MIN;
                return ;
            }
            ans = ans * 10 + temp;
            helper(s, i + 1, sign, ans,temp2,temp3);
        } else {
            return;
        }
    }
    int myAtoi(string s) {
        int i = 0;
        bool sign = true;
        int ans = 0;
        bool temp2=false;
        bool temp3=false;
        helper(s, i, sign, ans,temp2,temp3);
        if (!sign&&ans!=INT_MIN)
            ans = -ans;
        return ans;
    }
};