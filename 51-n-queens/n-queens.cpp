class Solution {
public:
    void find(int row,int n,vector<vector<string>>&ans,vector<string>&board,vector<bool>&column,vector<int>&rightDig,vector<int>&leftDig){
        if(row==n){
            ans.push_back(board);
            return ;
        }
        for(int j=0;j<n;j++){
            if(column[j]==0&&leftDig[n-1+row-j]==0&&rightDig[j+row]==0){
                column[j]=1;
                board[row][j]='Q';
                leftDig[n-1+row-j]=1;
                rightDig[row+j]=1;
                find(row+1,n,ans,board,column,rightDig,leftDig);
                column[j]=0;
                board[row][j]='.';
                leftDig[n-1+row-j]=0;
                rightDig[row+j]=0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        board[i].push_back('.');
        vector<bool>column(n,0);
        vector<int>leftDig(2*n-1);
        vector<int>rightDig(2*n-1);
        find(0,n,ans,board,column,leftDig,rightDig);
        return ans;
    }
};