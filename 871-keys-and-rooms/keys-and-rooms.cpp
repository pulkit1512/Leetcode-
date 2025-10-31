class Solution {
public:
    void dfs(int node,vector<vector<int>>&rooms,vector<bool>&visited,vector<int>&ans){
        visited[node]=1;
        ans.push_back(node);
        for(int i=0;i<rooms[node].size();i++){
            int neighbour =rooms[node][i];
            if(!visited[neighbour]){
                dfs(neighbour,rooms,visited,ans);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int v=rooms.size();
        vector<bool>visited(v,0);
        vector<int>ans;
        dfs(0,rooms,visited,ans);
        int count=ans.size();
        return count==v;
    }
};