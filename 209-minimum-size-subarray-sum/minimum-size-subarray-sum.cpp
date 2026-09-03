class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start=0,end=0;
        int ans=INT_MAX;
        int sum=0;
        while(end<nums.size()){
            sum+=nums[end];
            while(sum>=target){
                ans=min(ans,end-start+1);
                sum-=nums[start++];
            }
            end++;
        }
        // if(ans==INT_MAX) return 0;
        return ans==INT_MAX?0:ans;

    }
};