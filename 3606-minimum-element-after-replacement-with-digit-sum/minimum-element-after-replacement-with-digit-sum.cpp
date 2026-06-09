class Solution {
public:
    int minElement(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int result=0;
            while(nums[i]!=0){
                result=result+nums[i]%10;
                nums[i]/=10;
            }
            nums[i]=result;
        }
        return *min_element(nums.begin(),nums.end());
    }
};