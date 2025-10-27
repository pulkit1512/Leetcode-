class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int prevCount = 0;

        for (int i = 0; i < bank.size(); i++) {
            int currCount = 0;

            
            for (int j = 0; j < bank[i].length(); j++) {
                if (bank[i][j] == '1') {
                    currCount++;
                }
            }

            
            if (currCount > 0) {
                ans += prevCount * currCount;
                prevCount = currCount;
            }
        }

        return ans;
    }
};
