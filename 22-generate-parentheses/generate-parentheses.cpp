class Solution {
public:
    void helper(int n ,string s,int c1,int c2,vector<string>&ans){
        if(c1==n&&c2==n){
            ans.push_back(s);
            return ;
        }
        if(c1<n) helper(n,s+'(',c1+1,c2,ans);
        
        if(c2<c1) helper(n,s+')',c1,c2+1,ans);
        
       
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        helper(n,"(",1,0,ans);
        return ans;
    }
};