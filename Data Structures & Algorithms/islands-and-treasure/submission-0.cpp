class Solution {
public:
    vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(vector<vector<int>>& grid ,int row,int col,int i,int j,int dist=0)
    {
        if(i<0 || i>=row || j<0 || j>=col || grid[i][j]==-1 || grid[i][j]<dist) return ;
        if(grid[i][j]!=0) grid[i][j]=dist;

        for(auto x : directions)
        {
            dfs(grid,row,col,i+x.first,j+x.second,dist+1);
        }
        return;
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==0)
                {
                    dfs(grid,row,col,i,j);
                }
            }
        }
        
    }
};
