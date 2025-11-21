class Solution {
public:
    int jump(vector<int>& nums) {
        int jump = 0, l = 0;
        long long r = 0;
        int n = nums.size();
        
        while (r < n - 1) {
            long long maxIndex = 0;
            for (long long i = l; i <= r && i < n; ++i) {
                maxIndex = max(maxIndex, i + nums[i]);
            }
            l = r + 1;
            r = maxIndex;
            jump++;
        }
        
        return jump;
    }
};