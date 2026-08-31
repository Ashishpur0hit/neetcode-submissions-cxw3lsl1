class Solution {
public:
    vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1}};
    int rows,cols;
    int fun(vector<vector<int>>&grid,int i,int j)
    {
        if(i<0 || i>=rows || j<0 || j>=cols || grid[i][j]==0) return 0;
        grid[i][j]=0;
        int area=0;
        for(auto x : directions)
        {
            area += fun(grid,i+x.first,j+x.second);
        }
        return area+1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows = grid.size(),cols=grid[0].size();
        int max_area=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j]==1)
                {
                    int area = fun(grid,i,j);
                    max_area = max(max_area,area);
                }
            }
        }
        return max_area;
    }
};
