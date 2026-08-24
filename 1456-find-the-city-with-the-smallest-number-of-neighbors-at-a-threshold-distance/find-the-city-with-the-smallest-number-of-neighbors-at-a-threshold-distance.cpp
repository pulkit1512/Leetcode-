class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& times, int maxi) {

        vector<vector<pair<int, int>>> adj(n);
        vector<int>m(n);
        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adj[u].push_back({v, w});
            adj[v].push_back({u,w});
        }
        for (int i = 0; i < n; i++) {
            vector<int> dist(n, 1e8);
            vector<bool> visited(n, 0);

            priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>>pq;

            dist[i] = 0;
            pq.push({0, i});

            while (!pq.empty()) {
                auto [w, node] = pq.top();
                pq.pop();

                if (visited[node])
                    continue;
                visited[node] = 1;

                for (int k = 0; k < adj[node].size(); k++) {
                    auto [v, weight] = adj[node][k];

                    if (!visited[v] && dist[node] + weight < dist[v]) {
                        dist[v] = dist[node] + weight;
                        pq.push({dist[v], v});
                    }
                }
            }
            int count=0;
            for(int j=0;j<n;j++){
                if(dist[j]<=maxi) count++;
            }
            m[i]=count;
        }

        int ans = 0;
        int val=INT_MAX;
        for(int i=0;i<n;i++){
            if(m[i]<=val){
                val=m[i];
                ans=i;
            }
        }

        return ans;
    }
};