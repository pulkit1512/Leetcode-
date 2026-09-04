class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        
        int start=0,end=0,maxi=INT_MIN;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
        }
        while(end<nums.size()){
            m[nums[end]]++;
            while(m[maxi]>=k){
                ans+=nums.size()-end;
                m[nums[start]]--;
                start++;
            }
            end++;
        }
        return ans;
    }
};