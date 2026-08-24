class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pair<int,int>>> adj(n + 1);
        for(int i = 0; i < times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];

            adj[u].push_back({v, w});
        }

        vector<int> dist(n + 1, 1e8);
        vector<bool> visited(n + 1, 0);

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        dist[k] = 0;
        pq.push({0, k});
        
        while(!pq.empty()){
            auto [w, node] = pq.top();
            pq.pop();
            
            if(visited[node]) continue;
            visited[node] = 1;

            for(int i = 0; i < adj[node].size(); i++){
                auto [v, weight] = adj[node][i];

                if(!visited[v] && dist[node] + weight < dist[v]){
                    dist[v] = dist[node] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        
        int ans = 0;

        for(int i = 1; i <= n; i++){
            if(dist[i] >= 1e8) return -1; 
            ans = max(ans, dist[i]);
        }
        
        return ans;
    }
};