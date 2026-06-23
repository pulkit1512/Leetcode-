class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, pair<int,int>> m; 
        for (int i = 0; i < nums.size(); i++) {
            if (m[nums[i]].first > 0) { 
                if (i - m[nums[i]].second <= k) return true;
            }
            m[nums[i]].first++;       
            m[nums[i]].second = i;    
        }
        return false;
    }
};
