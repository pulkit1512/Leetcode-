class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long ans=0;
        long long x= *max_element(nums.begin(),nums.end());
        long long y= *min_element(nums.begin(),nums.end());
        return ans+=k*(x-y);
    }
};