class Solution {
public:
    void dfs(vector<vector<int>>& adj, int node, vector<bool>& visited) {

        visited[node] = 1;
        for (int i = 0; i < adj[node].size(); i++) {
            if (!visited[adj[node][i]]) {
                dfs(adj, adj[node][i], visited);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        if(connections.size()<n-1) return -1;
        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, 0);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(adj, i, visited);
                count++;
            }
        }
        return count-1;
    }
};