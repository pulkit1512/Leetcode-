class Solution {
public:
    int find(vector<int>&nums,int k){
        unordered_map<int,int>m;

        int start=0,end=0,total=0;
        int count=0;
        while(end<nums.size()&&start<=end){
            if(m[nums[end]]==0) count++;
            m[nums[end]]++;
            while(count>=k){
                total+=nums.size()-end;
                m[nums[start]]--;
                if(m[nums[start]]==0) count--;
                start++;
            }
            end++;
        }
        return total;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
         int x=find(nums,k);
         int y=find(nums,k+1);
         return x-y;      
    }
};