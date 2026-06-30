class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end());
        long long ans=0;
        reverse(nums.begin(),nums.end());
        for(int i=0;i<k;i++){
            if(mul>0){
                long long temp=((long long)nums[i]*mul);
                ans+=temp;
            }
            else{
                ans+=nums[i];
            }
            mul--;
        }
        return ans;
    }
};