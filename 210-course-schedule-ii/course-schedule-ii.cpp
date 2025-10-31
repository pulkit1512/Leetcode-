class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adj[u].push_back(v);
            indegree[v]++;
        }

        // now apply cycle detection in a directed graph if there is cycle
        // return true if there is no cycle and false if it is 
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        int count=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            count++;
            for(int i=0;i<adj[node].size();i++){
                int neighbour=adj[node][i];
                indegree[neighbour]--;
                if(indegree[neighbour]==0)
                q.push(neighbour);
            }
        }
        if(count==numCourses){
            return ans;
        }
        return {};
    }
};
