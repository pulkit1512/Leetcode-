class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    return {i, j};  // Return the indices as a vector
                }
            }
        }
        return {};  // Return empty vector if no solution found (though problem guarantees one)
    }
};