class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int total_sum=0;
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            total_sum+=nums[i];
        }
        for(int i=0;i<n-1;i++){
             int sum=0;
            for(int j=0;j<i;j++){
                sum+=nums[j];
            }
            if(abs(sum-(total_sum-sum))%2==0) ans++;
        }
        return ans;
    }
};