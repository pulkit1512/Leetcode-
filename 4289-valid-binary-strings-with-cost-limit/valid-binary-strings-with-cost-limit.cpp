class Solution {
public:
    void helper(int n,int k,int cost,string s,vector<string>&ans,int index){
        if(cost>k) return ;
        if(cost<=k&&s.size()==n){
            ans.push_back(s);
            return;
        }
        helper(n,k,cost,s+'0',ans,index+1);
        if((index>0&&s[index-1]!='1')||index==0){
            helper(n,k,cost+index,s+'1',ans,index+1);
        }
    }
    vector<string> generateValidStrings(int n, int k) {
        vector<string>ans;
        helper(n,k,0,"",ans,0);
        return ans;
    }
};