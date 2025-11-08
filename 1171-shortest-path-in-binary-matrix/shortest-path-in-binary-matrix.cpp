class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;

        queue<tuple<int, int, int>> q;
        q.push({0, 0, 1});
        grid[0][0] = 1;

        while (!q.empty()) {
            auto [r, c, length] = q.front();
            q.pop();

            if (r == n - 1 && c == n - 1) return length;

            for (int i = 0; i < 1; i++) {
                int x = r - 1, y = c - 1;
                if (x >= 0 && y >= 0 && grid[x][y] == 0) {
                    q.push({x, y, length + 1});
                    grid[x][y] = 1;
                }
            }

            for (int i = 0; i < 1; i++) {
                int x = r - 1, y = c;
                if (x >= 0 && grid[x][y] == 0) {
                    q.push({x, y, length + 1});
                    grid[x][y] = 1;
                }
            }

            for (int i = 0; i < 1; i++) {
                int x = r - 1, y = c + 1;
                if (x >= 0 && y < n && grid[x][y] == 0) {
                    q.push({x, y, length + 1});
                    grid[x][y] = 1;
                }
            }

            for (int i = 0; i < 1; i++) {
                int x = r, y = c - 1;
                if (y >= 0 && grid[x][y] == 0) {
                    q.push({x, y, length + 1});
                    grid[x][y] = 1;
                }
            }

            for (int i = 0; i < 1; i++) {
                int x = r, y = c + 1;
                if (y < n && grid[x][y] == 0) {
                    q.push({x, y, length + 1});
                    grid[x][y] = 1;
                }
            }

            for (int i = 0; i < 1; i++) {
                int x = r + 1, y = c - 1;
                if (x < n && y >= 0 && grid[x][y] == 0) {
                    q.push({x, y, length + 1});
                    grid[x][y] = 1;
                }
            }

            for (int i = 0; i < 1; i++) {
                int x = r + 1, y = c;
                if (x < n && grid[x][y] == 0) {
                    q.push({x, y, length + 1});
                    grid[x][y] = 1;
                }
            }

            for (int i = 0; i < 1; i++) {
                int x = r + 1, y = c + 1;
                if (x < n && y < n && grid[x][y] == 0) {
                    q.push({x, y, length + 1});
                    grid[x][y] = 1;
                }
            }
        }

        return -1;
    }
};
