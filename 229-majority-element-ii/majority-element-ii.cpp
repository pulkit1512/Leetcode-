class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0,count2=0;
        int c1,c2;
        for(int i=0;i<nums.size();i++){
            if(count1==0&&nums[i]!=c2){
                count1++;
                c1=nums[i];
            }
            else if(count2==0&&nums[i]!=c1){
                count2++;
                c2=nums[i];
            }
            else if(nums[i]==c1) count1++;
            else if(nums[i]==c2) count2++;
            else{
                count1--;
                count2--;
            }
        }
        int x1=0;
        int x2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==c1) x1++;
            if(nums[i]==c2) x2++;
        }
        vector<int>Ans;
        if(x1>nums.size()/3) Ans.push_back(c1);
        if(x2>nums.size()/3) Ans.push_back(c2);
        return Ans;
    }
};