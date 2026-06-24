class Solution {
public:
    void helper(int k,int n,int number,vector<int>&temp,vector<vector<int>>&ans,int sum){
        if(sum==n&&temp.size()==k){
            ans.push_back(temp);
            return ;
        }
        if(number>n||temp.size()==k||number>9) return ;
        temp.push_back(number);
        helper(k,n,number+1,temp,ans,sum+number);
        temp.pop_back();
        helper(k,n,number+1,temp,ans,sum);
;    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        int number=1;
        helper(k,n,number,temp,ans,0);
        return ans;
    }
};