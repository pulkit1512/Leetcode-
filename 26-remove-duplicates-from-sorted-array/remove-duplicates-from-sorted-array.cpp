class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int j = 0;
        for (int i = 1; i < nums.size(); i++) {
            while (i < nums.size() && nums[i] == nums[i - 1]) {
                i++;
            }
            if (i < nums.size()) {
                j++;
                nums[j] = nums[i];
            }
        }
        return j + 1;
    }
};