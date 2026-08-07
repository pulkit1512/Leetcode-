class Solution {
public:
    void dfs(vector<vector<int>>&adj,vector<bool>&visited,int node){
        visited[node]=1;
        for(int i=0;i<adj[node].size();i++){
            if(!visited[adj[node][i]]){
                dfs(adj,visited,adj[node][i]);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v=isConnected.size();
        vector<vector<int>>adj(v);
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count=0;
        vector<bool>visited(v,0);
        for(int i=0;i<v;i++){
            if(!visited[i]){
                dfs(adj,visited,i);
                count++;
            }
        }
        return count;
    }
};