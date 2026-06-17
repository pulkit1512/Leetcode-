class Solution {
public:
    char processStr(string s, long long k) {
        long long n = 0;
        // Forward pass: compute final length
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                n++;
            }
            else if (s[i] == '*') {
                if (n > 0) n--;
            }
            else if (s[i] == '#') {
                n *= 2;
            }
            else if (s[i] == '%') {
                continue;
            }
        }

        if (k + 1 > n) return '.'; // out of bounds

        // Backward pass
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '*') {
                n++;
            }
            else if (s[i] == '%') {
                k = n - k - 1;
            }
            else if (s[i] == '#') {
                n /= 2;
                if (k >= n) {
                    k -= n;
                }
            }
            else if (s[i] >= 'a' && s[i] <= 'z') {
                if (k == n - 1) return s[i]; 
                n--;
            }
        }

        return '.';
    }
};
