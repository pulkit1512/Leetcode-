class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int>color(v,-1);
        for(int i=0;i<v;i++){
            if(color[i]==-1){
                queue<int>q;
                q.push(i);
                color[i]=0;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    for(int j=0;j<graph[node].size();j++){
                        //if color is not assigned
                        int neighbour=graph[node][j];
                        if(color[neighbour]==-1){
                            color[neighbour]=(color[node]+1)%2;
                             q.push(neighbour);
                        }
                        else{
                            //check if assigned color is same as the neighbour and if same return 0                      
                            if(color[node]==color[neighbour]){
                                return 0;
                            }
                        }
                    }
                }
            }
        }
        return 1;
    }
};