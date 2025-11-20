class Solution {
public:
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+2);
        int first=0;
        int second=0;
        int third;
        for(int i=n-1;i>=0;i--){
           third=cost[i]+ min(first,second);
           second=first;
           first=third;
        }
        return min(second,first);
    }
};