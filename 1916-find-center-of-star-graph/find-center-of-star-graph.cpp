class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<int> adj[n];
        vector<int> outDeg(n, 0);

        for (int i = 0; i < n - 1; i++) {
            int u = edges[i][0] - 1;
            int v = edges[i][1] - 1;

            adj[u].push_back(v);
            adj[v].push_back(u);

            outDeg[u]++;
            outDeg[v]++;
        }

        for (int i = 0; i < n; i++) {
            if (outDeg[i] == n - 1) {
                return i + 1;
            }
        }

        return -1;
    }
};

