class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int max1=INT_MIN,max2=INT_MIN,max3=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            max1=max(max1,nums[i]);
        }
        for(int i=0;i<n;i++){
            if(nums[i]<max1){
                max2=max(max2,nums[i]);
            }
        }
        bool found=false;
        for(int i=0;i<n;i++){
            if(nums[i]<max2){
                max3=max(max3,nums[i]);\
                found=true;
            }
        }
        if(found){
            return max3;
        }
        return max1;
    }
};