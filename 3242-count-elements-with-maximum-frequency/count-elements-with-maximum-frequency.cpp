class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        int maxFreq=INT_MIN;
        for(auto it=freq.begin();it!=freq.end();it++){
            maxFreq=max(maxFreq,it->second);
        }
        int ans=0;
        for(auto it=freq.begin();it!=freq.end();it++){
            if(it->second==maxFreq) ans+=maxFreq;
        }
        return ans;
    }
};