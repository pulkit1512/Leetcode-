class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0;
        int twice=0;
        for(int i=0;i<nums.size();i++){
            ones=(nums[i]^ones)&(~twice);
            twice=(nums[i]^twice)&(~ones);
        }
        return ones;
    }
};