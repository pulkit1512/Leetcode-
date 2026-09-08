class Solution {
public:
    int helper(vector<int>&nums,int k){
        int first=0,second=0;
        int count=0;
        int total=0;
        while(second<nums.size()){
            if(nums[second]%2!=0) count++;
            while(count==k&&first<=second){
                total+=nums.size()-second;

                if(nums[first]%2!=0){
                    count--;
                }
                first++;
            }
            second++;
        }
        return total;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int x=helper(nums,k);
        int y=helper(nums,k+1);
        return x-y;
    }
};