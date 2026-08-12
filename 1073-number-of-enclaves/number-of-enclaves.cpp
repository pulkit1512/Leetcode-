int row[4] = {-1, 1, 0, 0};
int col[4] = {0, 0, 1, -1};
class Solution {
public:
    void dfs(vector<vector<int>>& board, int i, int j, int n, int m,
             vector<vector<bool>>& visited) {
        visited[i][j] = 1;
        for (int k = 0; k < 4; k++) {
            int r = i + row[k];
            int c = j + col[k];
            if (r >= 0 && r < n && c >= 0 && c < m && board[r][c] == 1) {
                if (!visited[r][c]) {
                    dfs(board, r, c, n, m, visited);
                }
            }
        }
    } 
    int numEnclaves(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, 0));
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 1) {
                dfs(board, i, 0, n, m, visited);
            }
            if (board[i][m - 1] == 1) {
                dfs(board, i, m-1, n, m, visited);
            }
        }

        for (int i = 0; i < m; i++) {
            if (board[0][i] == 1) {
                dfs(board, 0, i, n, m, visited);
            }
            if (board[n-1][i] == 1) {
                
                dfs(board, n-1 , i, n, m, visited);
            }
        }
        int count=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 1 && visited[i][j] == 0) {
                    count++;
                }
            }
        }
        return count;

    }
};