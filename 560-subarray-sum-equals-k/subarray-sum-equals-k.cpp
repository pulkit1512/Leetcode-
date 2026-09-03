class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            prefix.push_back(sum);
        }
        unordered_map<int, int> m;
        m[0]=1;
        int total=0;
        for(int i=0;i<n;i++){
            if(m[prefix[i]-k]!=0){
                total+=m[prefix[i]-k];
                m[prefix[i]]++;
            }
            else{
                m[prefix[i]]++;
            }
        }
        return total;
    }
};