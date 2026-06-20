class Solution {
public:
    bool check(vector<vector<char>>& board,int row,int col,int x ,int y)
    {
        char curr_char=board[x][y];
        int start_row=x/3,start_col=y/3;
        // checking in row and col
        for(int i=0;i<9;i++)
        {
            if(board[x][i]==curr_char && i!=y) return false;
            if(board[i][y]==curr_char && i!=x) return false;
            if(board[(start_row*3)+(i/3)][(start_col*3)+(i%3)]==curr_char && ((start_row*3)+(i/3)!=x  || (start_col*3)+(i%3)!=y)) return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = board.size(),col = board[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(board[i][j]!='.' && !check(board,row,col,i,j)) return false;
            }
        }
        return true;
    }
};
