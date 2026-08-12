int row[4] = {-1, 1, 0, 0};
int col[4] = {0, 0, -1, 1};
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        vector<vector<bool>> visited(n, vector<bool>(m, 0));
        queue<tuple<int, int, int>> q;
        for (int i = 0; i <n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j,0});
                    visited[i][j]=1;
                }
            }
        }
            
        
        while (!q.empty()) {
            auto [x, y, steps] = q.front();
            q.pop();
            ans[x][y]=steps;
            for (int k = 0; k < 4; k++) {
                int r = x + row[k];
                int c = y + col[k];
                if (r >= 0 && r < n && c >= 0 && c < m) {
                    if (!visited[r][c]) {
                        q.push({r, c, steps + 1});
                        visited[r][c] = 1;
                    }
                }
            }
        }
        return ans;
    }
};