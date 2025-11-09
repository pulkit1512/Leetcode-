class Solution {
public:
    bool bs(vector<int>&nums,int target){
        
        int start=0,end=nums.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target) return 1;
            if(nums[mid]<target) start=mid+1;
            else{
                end=mid-1;
            }
        }
        return 0;
       
    }
    vector<int> findMissingElements(vector<int>& nums) {
        int maxi = INT_MIN;
        int n = nums.size();
        int mini = INT_MAX;
        for (int i = 0; i < n;i++){
            maxi=max(nums[i],maxi);
            mini=min(nums[i],mini);
        }
            
        if (maxi - mini + 1 == n)
            return {};
        sort(nums.begin(),nums.end());
        int m=maxi-mini;
        vector<int>ans;
        for(int i=1;i<m;i++){
           if(!bs(nums,mini+i)){
               ans.push_back(mini+i);
           }
        }
        return ans;
    }
};