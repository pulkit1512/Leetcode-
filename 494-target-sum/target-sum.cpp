class Solution {
public:
    int find(vector<int>&arr,int target){
	    int n=arr.size();
	    vector<int>dp(target+1,0);
	    dp[0]=1;
	    for(int i=1;i<=n;i++){
	        vector<int>dp2(target+1,0);
	        dp2[0]=1;
	        for(int j=0;j<=target;j++){
	            if(arr[i-1]>j) dp2[j]=dp[j];
	            else dp2[j]=dp[j]+dp[j-arr[i-1]];
	        }
	        dp=dp2;
	    }
	    return dp[target];
	}
	int countPartitions(vector<int>& arr, int diff) {
		 int amount=0;
		 for(int i=0;i<arr.size();i++){
		     amount+=arr[i];
		 }
		 if((amount-diff)%2==0&&amount>=diff){
		     return find(arr,(amount-diff)/2);
		 }
		 return  0;
	}
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums,target);
    }
};