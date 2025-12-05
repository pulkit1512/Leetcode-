class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total_sum=0;
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            total_sum+=nums[i];
        }
        if(total_sum%2==0)return n-1;
        return 0;
    }
};