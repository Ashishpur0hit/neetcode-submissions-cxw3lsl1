class Solution {
public:
    vector<pair<int,int>> directions={{1,0},{-1,0},{0,1},{0,-1}};
    int dfs(vector<vector<int>>&grid,int row,int col,int i,int j)
    {
        if(i<0 || i>=row || j<0 || j>= col || grid[i][j]==0) return 0;
        grid[i][j]=0;
        int ans=0;
        for(auto x : directions) ans+=dfs(grid,row,col,i+x.first,j+x.second);
        return ans+1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size(),col = grid[0].size(),max_area=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1) max_area = max(max_area,dfs(grid,row,col,i,j));
            }
        }
        return max_area;
    }
};
