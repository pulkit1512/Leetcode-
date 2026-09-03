class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0]=1;
        int sum = 0, rem, total = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            rem = sum % k;
            if (rem < 0)
                rem += k;
            if (m[rem]==0){
                m[rem]++;
            }
            else{
                total+=m[rem];
                m[rem]++;
            }
        }
        return total;
    }
};