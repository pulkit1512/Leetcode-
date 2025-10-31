class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> adj[n];
        vector<int> inDeg(n, 0);

        // Build graph
        for (int i = 0; i < relations.size(); i++) {
            adj[relations[i][0] - 1].push_back(relations[i][1] - 1);
            inDeg[relations[i][1] - 1]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDeg[i] == 0) {
                q.push(i);
            }
        }

        vector<int> courseTime(n, 0);  // max time to reach each course

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int j = 0; j < adj[node].size(); j++) {
                int next = adj[node][j];
                inDeg[next]--;
                courseTime[next] = max(courseTime[next], courseTime[node] + time[node]);
                if (inDeg[next] == 0) {
                    q.push(next);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, courseTime[i] + time[i]);
        }

        return ans;
    }
};
