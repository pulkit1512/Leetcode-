class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int, int> m;
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            int first = 0, second = 0;
            int count = 0;
            int temp = k;
            while (second < s.size()) {
                if (s[second] == i + 'A') {
                    count++;
                } else {
                    temp--;

                    if (temp >= 0)
                        count++;
                    else {
                        while (temp < 0 && first <= second) {
                            if (s[first] == i + 'A') {
                                first++;
                                count--;
                            } else {
                                temp++;
                                first++;
                            }
                        }
                    }
                }
                second++;
                ans = max(ans, count);
            }
            
        }
        return ans;
    }
};
