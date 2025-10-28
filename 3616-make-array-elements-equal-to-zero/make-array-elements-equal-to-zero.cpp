class Solution {
public:
    bool helper(vector<int>&nums,int start,int dir){
           vector<int>arr=nums;
           int curr=start;
           while(curr>=0&&curr<arr.size()){
              if(arr[curr]==0){
                curr+=dir;
              }
              else{
                arr[curr]--;
                dir*=-1;
                curr+=dir;
              }
           }
           for(int i=0;i<arr.size();i++){
            if(arr[i]!=0) return false;
           }
           return true;

    }
    int countValidSelections(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                if(helper(nums,i,1)) ans++;
                if(helper(nums,i,-1)) ans++;
            }
        }
        return ans;
    }
};