class Solution {
public:
    bool find(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        int ans=0;
        vector<int>dp(sum+1,0);
        dp[0]=1;
        // for(int i=0;i<=n;i++){
        //     dp[i][0]=1;
        // }
        for(int i=1;i<=n;i++){
            vector<int>dp2(sum+1,0);
            dp2[0]=1;
            for(int j=1;j<=sum;j++){
                
                if(j-arr[i-1]<0) dp2[j]=dp[j];
                else dp2[j]=dp[j-arr[i-1]]||dp[j];
            }
            dp=dp2;
            if(dp[sum]) return 1;
        }
        return dp[sum];    
        
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        int n=nums.size();
        if (sum % 2 == 0) {
            return find(nums, sum/2);
        }
        return 0;
    }
};