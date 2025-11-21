class Solution {
public:
    int find(int index,int n,vector<int>&dp,vector<int>&nums){
        if(index>=n) return 0;
        if(index==n-1) return nums[index];
        if(dp[index]!=-1) return dp[index];
        return dp[index]=max(nums[index]+find(index+2,n,dp,nums),find(index+1,n,dp,nums)); 
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return find(0,n,dp,nums);
    }
};