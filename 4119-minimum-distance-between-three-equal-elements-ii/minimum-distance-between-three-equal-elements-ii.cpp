class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>>m;
        for(int i=0;i<n;i++){
            m[nums[i]].push_back(i);
        }
        int ans=INT_MAX;
        for(auto it=m.begin();it!=m.end();it++){
             int first=it->first;
             vector<int> second=it->second;
             if(second.size()>=3){
                 for(int i=0;i<=second.size()-3;i++){
                     ans=min(ans,abs(second[i]-second[i+1])+abs(second[i+1]-second[i+2])+abs(second[i+2]-second[i]));
                 }
             }
            
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};