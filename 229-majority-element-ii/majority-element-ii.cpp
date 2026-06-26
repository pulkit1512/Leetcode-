class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
         
        vector<int> ans;
        int n = nums.size();
        int count = 1;

        sort(nums.begin(), nums.end()); // Group duplicates

        if (n == 1) {
            ans.push_back(nums[0]);
            return ans;
        }

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                count++;
            } else {
                if (count > n / 3) {
                    ans.push_back(nums[i]);
                }
                count = 1;
            }
        }

        
        if (count > n / 3) {
            ans.push_back(nums[n - 1]);
        }

        return ans;
    }
};
