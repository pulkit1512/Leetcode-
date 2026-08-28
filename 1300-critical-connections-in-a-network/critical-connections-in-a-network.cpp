class Solution {
public:
    void dfs(int node,int parent,vector<vector<int>>&adj,vector<int>&disc,vector<int>&low,int  count,vector<vector<int>>&ans,vector<bool>&visited){
        disc[node]=low[node]=count;
        visited[node]=1;
        for(int i=0;i<adj[node].size();i++){
            int neigh=adj[node][i];

            if(neigh==parent) continue;

            else if(visited[neigh]) low[node]=min(low[node],low[neigh]);
            else{
                // count++;
                dfs(neigh,node,adj,disc,low,count+1,ans,visited);
                if(disc[node]<low[neigh]){
                    ans.push_back({node,neigh});
                }
                low[node]=min(low[node],low[neigh]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);

        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>disc(n);
        vector<int>low(n);

        vector<bool>visited(n,0);
        int count=0;
        vector<vector<int>>ans;

        dfs(0,-1,adj,disc,low,count,ans,visited);


        return ans;

    }
};