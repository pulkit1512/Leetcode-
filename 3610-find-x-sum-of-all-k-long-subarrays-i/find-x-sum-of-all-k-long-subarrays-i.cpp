bool cmp(pair<int, int>& a, pair<int, int>& b) {
    if (a.second == b.second) {
        return a.first > b.first; 
    }
    return a.second > b.second; 
}

class Solution {
public:
    int helper(vector<int>nums,int x){
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int sum=0;
        vector<pair<int,int>>freq(m.begin(),m.end());
        sort(freq.begin(),freq.end(),cmp);
        for(int i=0;i<freq.size();i++){
            if(!x) break;
            sum+=freq[i].first*freq[i].second;
            x--;
        }
        return sum; 
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (i + k - 1 < n) {
                vector<int> sub(nums.begin() + i, nums.begin() + i + k);
                int xsum = helper(sub, x);
               ans.push_back(xsum);
            }

        }
        return ans;
    }
};