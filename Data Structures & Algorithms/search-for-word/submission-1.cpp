class Solution {
public:
    vector<vector<int>>directions = {{1,0},{-1,0},{0,1},{0,-1}};
    bool dfs(vector<vector<char>>& board,vector<vector<bool>>& vis,string word,int i,int j,int row,int col,int index=0)
    {
        if(i<0 || i>=row || j<0 || j>=col || vis[i][j] || board[i][j]!=word[index]) return false;
        if(index==word.size()-1) return true;
        vis[i][j]=true;
        bool ans = false;
        for(auto x : directions)
        {
            ans = ans || dfs(board,vis,word,i+x[0],j+x[1],row,col,index+1);
        }
        vis[i][j]=false;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(),col = board[0].size();
        vector<vector<bool>>vis(row,vector<bool>(col,false));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(board[i][j]==word[0] && dfs(board,vis,word,i,j,row,col)) return true;
            }
        }
        return false;
        
    }
};
