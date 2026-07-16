class Solution {
public:
    bool find(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        int ans=0;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                
                if(j-arr[i-1]<0) dp[i][j]=dp[i-1][j];
                else dp[i][j]=dp[i-1][j-arr[i-1]]||dp[i-1][j];
            }
            if(dp[i][sum]) return 1;
        }
        return dp[n][sum];    
        
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