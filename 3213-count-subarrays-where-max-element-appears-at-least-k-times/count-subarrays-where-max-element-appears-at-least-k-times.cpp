class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
         int count=0;
        
        int start=0,end=0,maxi=INT_MIN;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
        }
        while(end<nums.size()){
            if(nums[end]==maxi) count++;
            while(count>=k){
                ans+=nums.size()-end;
                if(nums[start]==maxi) count--;
                start++;
            }
            end++;
        }
        return ans;
    }
};