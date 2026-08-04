class Solution {
public:
    
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            for(int prev=i-1;prev>=-1;prev--){
                int not_take=dp[prev+1];
                int take=0;
                if(prev==-1||arr[i]>arr[prev]){
                  take= 1+dp[i+1];
                }
                dp[prev+1]=max(take,not_take);
            }
        }
        return dp[0];
    }
};