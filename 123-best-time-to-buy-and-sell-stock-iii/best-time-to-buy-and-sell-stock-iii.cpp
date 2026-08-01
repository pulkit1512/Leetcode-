class Solution {
public:
    int find(vector<int>&prices,int buy,int count,int index,vector<vector<vector<int>>>&dp){
        if(count ==2) return 0;
        if(index==prices.size()) return 0;
        if(dp[index][buy][count]!=-1) return dp[index][buy][count];
        int profit=INT_MIN;
        if(buy){
            profit=max(-prices[index]+find(prices,0,count,index+1,dp),find(prices,1,count,index+1,dp));
        }
        else{
            profit=max(prices[index]+find(prices,1,count+1,index+1,dp),find(prices,0,count,index+1,dp));
        }
        return dp[index][buy][count]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return find(prices,1,0,0,dp);
    }
};