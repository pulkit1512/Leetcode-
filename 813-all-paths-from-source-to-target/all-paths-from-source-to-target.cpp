class Solution {
public:
    void dfs(int node,vector<vector<int>>&graph,vector<bool>&visited,vector<vector<int>>&ans,vector<int>&arr,int V){
        visited[node]=1;
        arr.push_back(node);
        if(node==V-1){
            ans.push_back(arr);
        }
        for(int i=0;i<graph[node].size();i++){
            int neighbour=graph[node][i];
            if(!visited[neighbour]){
                dfs(neighbour,graph,visited,ans,arr,V);
            }
        }
        arr.pop_back();
        visited[node]=0;

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        int V=graph.size();
        vector<bool>visited(V,0);
        vector<int>arr;
        dfs(0,graph,visited,ans,arr,V);
        return ans;
    }
};