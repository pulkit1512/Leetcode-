class Solution {
public:
    int find(int index,int n,vector<int>&dp,vector<int>&nums){
        if(index>=n) return 0;
        if(dp[index]!=-1) return dp[index];
        return dp[index]=max(nums[index]+find(index+2,n,dp,nums),find(index+1,n,dp,nums)); 
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        int first=0;
        int second=0;
        int third;
        for(int i=n-1;i>=0;i--){
           third=max(second+nums[i],first);
           second=first;
           first=third;
        }
         return  third;
    }
};