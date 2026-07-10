class Solution {
public:
    vector<vector<int>> directions={{1,0},{-1,0},{0,1},{0,-1}};
    int row,col;
    void dfs(vector<vector<char>>& board,int i,int j)
    {
        if(i<0 || i>=row || j<0 || j>=col || board[i][j]!='O') return;
        board[i][j]='T';
        for(auto x : directions)
        {
            dfs(board,i+x[0],j+x[1]);
        } 
    }
    void solve(vector<vector<char>>& board) {
        row=board.size(),col=board[0].size();
        for(int i=0;i<row;i++)
        {
            dfs(board,i,0);
            dfs(board,i,col-1);
        }
        for(int j=0;j<col;j++)
        {
            dfs(board,0,j);
            dfs(board,row-1,j);
        }


        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='T') board[i][j]='O';
            }
        }
        

    }
};
