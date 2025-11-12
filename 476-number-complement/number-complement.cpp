class Solution {
public:
    string helper(int n) {
        string s;
        while (n) {
            int x = n % 2;
            s.push_back('0' + x);
            n = n / 2;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    int findComplement(int num) {
        string str = helper(num);
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '0') {
                str[i] = '1';
            } else {
                str[i] = '0';
            }
        }
        return stoi(str, nullptr, 2);
    }
};
