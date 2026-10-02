class Solution {
public:
    bool check(vector<vector<char>>&board,int x,int y)
    {
        int start_row =x/3,start_col=y/3;
        //check row
        for(int i=0;i<9;i++)
        {
            if(i!=y && board[x][i]==board[x][y]) return false;
        }

        //check col
        for(int j=0;j<9;j++)
        {
            if(x!=j && board[j][y]==board[x][y]) return false;
        }


        for(int k = 0;k<9;k++)
        {
            int i = (start_row *3) + (k/3),j= (start_col*3) + (k%3);
            if(x!=i && y!=j  && board[i][j]==board[x][y]) return false;
        }

        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    if(!check(board,i,j)) return false;
                }
            }
        }
        return true;
    }
};
