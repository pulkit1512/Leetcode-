struct cmp {
    bool operator()(const string& a, const string& b) const {
        if (a.size() != b.size()) return a.size() > b.size();
        return a > b;
    }
};

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        string ans="";
        
        priority_queue<string,vector<string>,cmp>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
};