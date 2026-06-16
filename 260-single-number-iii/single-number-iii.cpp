class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); ) {
            if (i == nums.size() - 1 || nums[i] != nums[i + 1]) {
                ans.push_back(nums[i]);
                i++;
            } else {
                
                i += 2;
            }
        }
        
        return ans;
    }
};