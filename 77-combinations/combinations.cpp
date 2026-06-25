class Solution {
public:
    void helper(int n ,int k,int number,vector<int>&temp,vector<vector<int>>&ans){
        if(temp.size()==k){
            ans.push_back(temp);
            return ;
        }
        if(number>n||temp.size()>k) return ;
        temp.push_back(number);
        helper(n,k,number+1,temp,ans);
        temp.pop_back();
        helper(n,k,number+1,temp,ans);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;
        helper(n,k,1,temp,ans);
        return ans;
    }
};