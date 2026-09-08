class Solution {
public:
    int find(vector<int>& nums,int k){
        unordered_map<int,int>m;
        int first=0,second=0;
        int count=0;
        int ans=0;
        while(second<nums.size()){
            if(m[nums[second]]==0) count++;
            m[nums[second]]++;
            while(count==k&&first<=second){
                ans+=nums.size()-second;
                m[nums[first]]--;
                if(m[nums[first]]==0) count--;
                first++;
            }
            second++;
        }
        return ans;

    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int x=find(nums,k);
        int y=find(nums,k+1);
        return x-y;
    }
};