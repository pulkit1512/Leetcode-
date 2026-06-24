class Solution {
public:
    void helper(vector<int>nums,int index,vector<int>&temp,vector<vector<int>>&ans){
        if(index==nums.size()){
            ans.push_back(temp);
            return ;
        }
        temp.push_back(nums[index]);
        helper(nums,index+1,temp,ans);
        temp.pop_back();
        int x=index+1;
        while(x<nums.size()&&nums[x]==nums[index]) x++;
        helper(nums,x,temp,ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(nums.begin(),nums.end());
        helper(nums,0,temp,ans);
        return ans;
    }
};