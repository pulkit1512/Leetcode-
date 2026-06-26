class Solution {
public:
    void helper(vector<int>nums,int index,vector<int>&temp,vector<bool>&temp2,vector<vector<int>>&ans){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return ;
        }
        if(index>=nums.size()) return ;
        if(!temp2[index]){
            temp.push_back(nums[index]);
            temp2[index]=1;
            helper(nums,0,temp,temp2,ans);
            temp.pop_back();
            temp2[index]=0;
        }
        helper(nums,index+1,temp,temp2,ans);
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        vector<bool>temp2(nums.size(),0);
        helper(nums,0,temp,temp2,ans);
        return ans;
    }
};