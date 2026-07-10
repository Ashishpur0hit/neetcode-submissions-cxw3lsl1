class Solution {
public:
    int row , col ;
    vector<pair<int,int>>directions = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(vector<vector<int>>& heights,vector<vector<bool>>& ocean , int i,int j,int prev=0)
    {
        if(i<0 || i>=row || j<0 || j>=col || ocean[i][j] || heights[i][j]<prev) return ;
        ocean[i][j]=true;
        for(auto x : directions)
        {
            dfs(heights,ocean,i+x.first,j+x.second,heights[i][j]);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        row = heights.size() , col = heights[0].size();
        vector<vector<bool>>pac(row,vector<bool>(col,false));
        vector<vector<bool>>atl(row,vector<bool>(col,false));
        vector<vector<int>>ans;

        for(int i=0;i<col;i++)
        {
            dfs(heights,pac,0,i);
            dfs(heights,atl,row-1,i);
        }
        for(int i=0;i<row;i++)
        {
            dfs(heights,pac,i,0);
            dfs(heights,atl,i,col-1);
        }

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(pac[i][j] && atl[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
