class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<bool>inc(n,false),dec(n,false);
        bool check = false;
        if (n == 2)
            return abs(nums[0] - nums[1]);
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                check = true;
            }
        }
        if (!check)
            return -1;
        inc[0] = 1;
        dec[n - 1] = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]&&inc[i-1]) {
                inc[i] = 1;
            } 
        }
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1]&&dec[i+1]) {
                dec[i] = 1;
            }
        }
        vector<long long>prefix(n,0),suffix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]+nums[i];
        }
        
        vector<int> arr;
        long long ans=LLONG_MAX;
        for (int i = 0; i < n-1; i++) {
            if (inc[i] && dec[i + 1]) {
                long long left=prefix[i];
                long long right=suffix[i+1];
                ans=min(ans,abs(left-right));
                
            }
        }
        if(ans==LLONG_MAX) return -1;
        return ans;
    }
};