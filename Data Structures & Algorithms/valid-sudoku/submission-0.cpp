class Solution {
public:
    bool isValid(int row,int col,vector<vector<char>>board)
    {
        if(board[row][col]=='.') return true;
        for(int i=0;i<9;i++)
        {
            if(i!=col and board[row][i]==board[row][col]) return false;
            if(i!=row and board[i][col]==board[row][col]) return false;
            if(row/3*3+i/3!=row and col/3*3+i%3!=col and board[row/3*3+i/3][col/3*3+i%3]==board[row][col]) return false;
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(!isValid(i,j,board)) return false;
            }
        }
        return true;
    }
};
