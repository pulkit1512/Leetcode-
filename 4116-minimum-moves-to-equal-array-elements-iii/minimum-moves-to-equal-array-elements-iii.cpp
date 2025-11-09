class Solution {
public:
    int minMoves(vector<int>& nums) {
         int maxi = INT_MIN;
        int n = nums.size();
        
        for (int i = 0; i < n;i++){
            maxi=max(nums[i],maxi);
            
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=maxi-nums[i];
        }
        return ans;
    }
};