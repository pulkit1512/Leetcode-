class Solution {
public:
    int find(vector<int>&nums,int target,int index,int sum){
        if(index==nums.size()&&sum==target) return 1;
        if(index>=nums.size()) return 0;
        
        return find(nums,target,index+1,sum-nums[index])+find(nums,target,index+1,sum+nums[index]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return find(nums,target,0,0);
    }
};