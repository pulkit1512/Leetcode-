class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int v=rooms.size();
        vector<bool>visited(v,0);
        queue<int>q;
        q.push(0);
        visited[0]=1;
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int i=0;i<rooms[node].size();i++){
                int neighbour=rooms[node][i];
                if(!visited[neighbour]){
                    visited[neighbour]=1;
                    q.push(neighbour);
                }
            }        }
            int count=ans.size();
            return count==v;
    }
};