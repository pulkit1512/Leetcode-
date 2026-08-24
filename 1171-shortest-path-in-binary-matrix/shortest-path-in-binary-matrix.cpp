class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        queue<tuple<int, int, int>> q;
        q.push({0, 0, 1});
        grid[0][0] = 1;

        while (!q.empty()) {
            auto [x, y, length] = q.front();
            q.pop();

            if (x == n - 1 && y == n - 1)
                return length;
            int row[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
            int col[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

            for(int i=0;i<8;i++){
                int r=x+row[i];
                int c=y+col[i];

                if(r>=0&&r<n&&c>=0&&c<n&&grid[r][c]==0){
                    grid[r][c]=1;
                    q.push({r,c,length+1});
                } 
            }

        }

        return -1;
    }
};
