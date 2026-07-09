class Solution {
public:
    vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(vector<vector<char>>& grid,int row,int col,int i,int j)
    {
        if(i<0 || i>=row || j<0 ||j>=col || grid[i][j]=='0') return ;
        grid[i][j]='0';
        for(auto x : directions) dfs(grid,row,col,i+x.first,j+x.second);
    }
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size(),col=grid[0].size(),islands=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]=='1')
                {
                    islands++;
                    dfs(grid,row,col,i,j);
                }
            }
        }
        return islands;
    }
};
