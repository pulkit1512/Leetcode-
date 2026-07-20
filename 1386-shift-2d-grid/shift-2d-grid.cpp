class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int total = n * m;
        k = k % total;
        vector<vector<int>> ans(n, vector<int>(m, 0));
        while (k--) {
            
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (i == n - 1 && j == m - 1) {
                        ans[0][0] = grid[n - 1][m - 1];
                    }
                    else if (j == m - 1) {
                        ans[i + 1][0] = grid[i][m - 1];
                    }
                    else {
                        ans[i][j + 1] = grid[i][j];
                    }
                }
            }
            grid = ans; // update grid for the next shift
        }
        return grid;
    }
};