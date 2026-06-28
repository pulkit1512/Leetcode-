int row[] = {-1, 1, 0, 0};
int col[] = {0, 0, -1, 1};
class Solution {
public:
    bool valid(int i,int j,int m ,int n){
        return i>=0&&i<=m-1&&j>=0&&j<=n-1;
    }
    bool helper(vector<vector<char>>& board, string word,vector<vector<bool>>&visited,int m,int n,string &temp,int i,int j){
        if(temp != word.substr(0, temp.length())) return false;
        if(temp==word) return true;
        if(i==m&&j==m) return false;
        visited[i][j]=1;
        for(int k=0;k<4;k++){
            if(valid(i+row[k],j+col[k],m,n)&&!visited[i+row[k]][j+col[k]]){
                temp.push_back(board[i+row[k]][j+col[k]]);
                if(helper(board,word,visited,m,n,temp,i+row[k],j+col[k])){
                    return true;
                }
                temp.pop_back();
            }
        }
        visited[i][j]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(); 
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    string temp="";
                    temp.push_back(board[i][j]);
                    if(helper(board,word,visited,m,n,temp,i,j)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};