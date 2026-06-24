class Solution {
public:
    void helper(vector<int>nums,int index,vector<int>&temp,vector<vector<int>>&ans){
        if(index==nums.size()){
            ans.push_back(temp);
            return;
        }
        // take this element
        temp.push_back(nums[index]);
        helper(nums,index+1,temp,ans);
        temp.pop_back();
        helper(nums,index+1,temp,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        helper(nums,0,temp,ans);
        return ans;
    }
};