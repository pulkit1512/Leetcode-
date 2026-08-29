class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
       sort(nums.begin(),nums.end());
       int value=k;
       for(int i=0;i<nums.size();i++){
          if(nums[i]==value){
            value+=k;
          }
       }
       return value;
    }
};