class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it=m.begin();it!=m.end();it++){
            pq.push({it->
            second,it->first});
        }
        for(int i=0;i<k;i++){
            int n=pq.top().second;
            pq.pop();
            ans.push_back(n);
        }
        return ans;
    }
};