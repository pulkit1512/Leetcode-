class Solution {
public:
    int myAtoi(string s) {
        int ans = 0;
        bool sign = true;
        bool temp2=false;
        int temp3=false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' '&&!temp3&&!temp2)
                continue;
            if(i>0&&s[i-1]=='0' &&s[i]=='-'&&ans==0) return 0;
            if (s[i] == '-'&&!temp2&&!temp3) {
                sign = false;
                temp2=true;
                continue;
            }

            if (s[i] == '+' &&!temp2&&!temp3) {
                sign = true;
                temp2=true;
                continue;
            }

            if (s[i] >= '0' && s[i] <= '9') {
                int temp = s[i] - '0';
                temp3=true;
                if (ans > (INT_MAX - temp) / 10) {
                    return sign ? INT_MAX : INT_MIN;
                }

                ans = ans * 10 + temp;
            } else {
                break;
            }
        }

        if (!sign)
            ans = -ans;
        return ans;
    }
};
