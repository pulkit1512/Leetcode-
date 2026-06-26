class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        long long cumsum=0;
        m[cumsum]=1;
        long long  pre=0;
        long long  ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                pre+=m[cumsum];
                cumsum++;
            }
            else{
                cumsum--;
                pre-=m[cumsum];
            }
            m[cumsum]++;
            ans+=pre;
        }
        return ans;
    }
};