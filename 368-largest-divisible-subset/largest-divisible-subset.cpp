class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
         int n=nums.size();
         vector<int>dp(n,1),hash(n);
         int maxi=1;
         int lastIndex=0;
         sort(nums.begin(),nums.end());
         for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0&&dp[prev]+1>dp[i]){
                    hash[i]=prev;
                    dp[i]=1+dp[prev];
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastIndex=i;
            }
         }
         vector<int>ans;
         ans.push_back(nums[lastIndex]);
         while(lastIndex!=hash[lastIndex]){
            lastIndex=hash[lastIndex];
            ans.push_back(nums[lastIndex]);
         }
         reverse(ans.begin(),ans.end());
         return ans;
    }
};