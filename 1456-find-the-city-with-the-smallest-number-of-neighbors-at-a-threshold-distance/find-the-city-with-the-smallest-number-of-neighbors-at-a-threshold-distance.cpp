class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& times, int maxi) {
        vector<vector<int>>adj(n,vector<int>(n,1e8));
        for(int i=0;i<n;i++){
            adj[i][i]=0;
        }
        for(int i=0;i<times.size();i++){
            int u=times[i][0];
            int v=times[i][1];
            int w=times[i][2];
            adj[u][v]=w;
            adj[v][u]=w;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(adj[j][i]==1e8||adj[i][k]==1e8) continue;
                    adj[j][k]=min(adj[j][k],adj[j][i]+adj[i][k]);
                }
            }
        }
        int mini=INT_MAX;
        int ans=0;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
               if(adj[i][j]!=1e8&&adj[i][j]<=maxi) count++;
            }
            if(mini>=count){
                mini=count;
                ans=i;
            }
        }
        return ans;
    }
};