class Solution {
public:
    void helper(vector<int>nums,int index,vector<int>&temp,vector<bool>&visited,vector<vector<int>>&ans){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return ;
        }
        for(int i=0;i<nums.size();i++){
            if(visited[i]==0){
                if(i>0&&nums[i]==nums[i-1]&&!visited[i-1]) continue;
                temp.push_back(nums[i]);
                visited[i]=1;
                helper(nums,index+1,temp,visited,ans);
                visited[i]=0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<bool>visited(nums.size(),0);
        vector<int>temp;
        helper(nums,0,temp,visited,ans);
        return ans;
    }
};