class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_map<int,bool>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=1;
        }

        for(int i=k;i<1e8;i+=k){
            if(!m[i]){
                return i;
            }
        }
        return -1;
    }
};