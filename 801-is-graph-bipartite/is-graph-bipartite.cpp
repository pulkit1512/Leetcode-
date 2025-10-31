class Solution {
public:
    bool isbip(int node, vector<vector<int>> &adj, vector<int> &color) {
        for (int neighbour : adj[node]) {
            if (color[neighbour] == -1) {
                color[neighbour] = 1 - color[node];
                if (!isbip(neighbour, adj, color)) {
                    return false;
                }
            } else if (color[neighbour] == color[node]) {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>> &adj) {
        int V=adj.size();
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                color[i] = 0;
                if (!isbip(i, adj, color)) {
                    return false;
                }
            }
        }
        return true;
    }
};

