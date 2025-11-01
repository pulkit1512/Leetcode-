class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>path(n,-1);
        vector<bool>visited(n,0);
        queue<int>q;
        q.push(source);
        path[source]=0;
        visited[source]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int i=0;i<adj[node].size();i++){
                if(!visited[adj[node][i]]){
                    visited[adj[node][i]]=1;
                    q.push(adj[node][i]);
                    path[adj[node][i]]=path[node]+1;
                }
            }
        }
        if(path[destination]==-1) return 0;
         return 1;
    }
};