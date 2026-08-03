class Solution {
public:
    int find(string word1,string word2,int i,int j,vector<vector<int>>&dp){
        if(i<=0) return  j;
        if(j<=0) return  i;
        if(dp[i-1][j-1]!=-1) return dp[i-1][j-1];
        if(word1[i-1]==word2[j-1]) return dp[i-1][j-1]=find(word1,word2,i-1,j-1,dp);
        else{
            return dp[i-1][j-1] =min(1+find(word1,word2,i,j-1,dp),min(1+find(word1,word2,i-1,j,dp),1+find(word1,word2,i-1,j-1,dp)));
        }
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return find(word1,word2,n,m,dp);
    }
};