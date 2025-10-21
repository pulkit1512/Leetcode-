class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans1=INT_MIN;
        int ans2=INT_MIN;
        int product=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
           
           product*=nums[i];
           ans1=max(ans1,product);
           if(nums[i]==0) product=1;
        }
        product=1;
        for(int i=n-1;i>=0;i--){
            product*=nums[i];
            ans2=max(ans2,product);
            if(nums[i]==0) product=1;
        }
        ans1=max(ans1,ans2);
        return ans1;
    }
};