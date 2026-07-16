class Solution {
public:
    bool find(vector<int>& arr, int target, int index,
              vector<vector<int>>& dp) {
        if (target == 0)
            return 1;
        if (index < 0 || target < 0)
            return 0;
        if (dp[index][target] != -1)
            return dp[index][target];
        return dp[index][target] =
                   find(arr, target - arr[index], index - 1, dp) ||
                   find(arr, target, index - 1, dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        int n=nums.size();
        if (sum % 2 == 0) {
            vector<vector<int>> dp(n, vector<int>(sum/2+1,-1));
            return find(nums, sum/2, nums.size() - 1, dp);
        }
        return 0;
    }
};