#include <vector>
using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        // mark guards as 1
        for (int i = 0; i < guards.size(); i++) {
            grid[guards[i][0]][guards[i][1]] = 1;
        }

        // mark walls as 2
        for (int i = 0; i < walls.size(); i++) {
            grid[walls[i][0]][walls[i][1]] = 2;
        }

        for (int i = 0; i < guards.size(); i++) {
            int x = guards[i][0];
            int y = guards[i][1];

            // for south
            for (int j = x + 1; j < m; j++) {
                if (grid[j][y] == 1 || grid[j][y] == 2)
                    break;
                if (grid[j][y] == 0)
                    grid[j][y] = 3;
            }

            // for north so start from the x-1 tile the 0 down to up
            for (int j = x - 1; j >= 0; j--) {
                if (grid[j][y] == 1 || grid[j][y] == 2)
                    break;
                if (grid[j][y] == 0)
                    grid[j][y] = 3;
            }

            // for east start from the y till n
            for (int j = y + 1; j < n; j++) {
                if (grid[x][j] == 1 || grid[x][j] == 2)
                    break;
                if (grid[x][j] == 0)
                    grid[x][j] = 3;
            }

            // for west start from the y-1 to 0
            for (int j = y - 1; j >= 0; j--) {
                if (grid[x][j] == 1 || grid[x][j] == 2)
                    break;
                if (grid[x][j] == 0)
                    grid[x][j] = 3;
            }
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    count++;
            }
        }

        return count;
    }
};
