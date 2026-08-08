class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        vector<int> InDegree(n, 0);
        vector<int> OutDegree(n, 0);

        for (int i = 0; i < trust.size(); i++) {
            int u = trust[i][0];
            int v = trust[i][1];
            InDegree[v-1]++;
            OutDegree[u-1]++;
        }
        int count=0;
        int ans=-1;
        for(int i=0;i<n;i++){
            if(InDegree[i]==n-1&&OutDegree[i]==0){
                ans=i;
                count++;
            }
        }
        if(count==1) return ans+1;
        return -1;
    }
};