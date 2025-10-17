class Solution {
public:
    bool check(vector<int>& nums) {
        int count =0;
        for(int i=0;i<nums.size();i++){
            // this condition check such that the next element is smaller than the previous element if this happens more than one time than the array is not sorted if this happen one time than the array is rotated x times if this happen 0 time than the array is sorted or rotated n time 
            if(nums[i]>nums[(i+1)%nums.size()]){
            count ++;
            }


        }
        if(count>1){
            return false;
        }
        return true ;

    }
};