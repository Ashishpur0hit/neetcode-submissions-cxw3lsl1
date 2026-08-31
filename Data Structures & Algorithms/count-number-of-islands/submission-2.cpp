class Solution {
public:
    vector<pair<int,int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
    int rows,cols;
    void fun(vector<vector<char>>&grid,int i,int j)
    {
        if(i<0 || i>=rows || j<0 || j>=cols || grid[i][j]=='0') return ;
        grid[i][j]='0';
        for(auto x : directions)
        {
            fun(grid,i+x.first,j+x.second);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size(),cols=grid[0].size();
        int islands=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j]=='1')
                {
                    islands++;
                    fun(grid,i,j);
                }
            }
        }
        return islands;
    }
};
