class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<tuple<int,int,int>>q;
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j,0});
                }
                if(grid[i][j]==1) count++;
            }
        }
        if(count==0) return 0;
        int ans=0;
        while(!q.empty()){
            auto [x,y,step]=q.front();
            q.pop();

            int row[4]={-1,1,0,0};
            int col[4]={0,0,-1,1};
            ans=step;
            for(int k=0;k<4;k++){
                int r=x+row[k];
                int c=y+col[k];

                if(r>=0&&r<n&&c>=0&&c<m&&grid[r][c]==1){
                     grid[r][c]=2;
                     count--;
                     q.push({r,c,step+1});
                }
            }
        }
        if(count!=0) return -1;
        if(ans==0) return -1;
        return ans;
    }
};