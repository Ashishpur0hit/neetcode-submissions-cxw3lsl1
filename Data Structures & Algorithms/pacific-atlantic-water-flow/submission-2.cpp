class Solution {
public:
    vector<pair<int,int>>directions={{1,0},{0,1},{-1,0},{0,-1}};
    int rows,cols;
    void solve(vector<vector<int>>&heights,int i,int j,int src,vector<vector<int>>&temp)
    {
        if(i<0 || i>=rows || j<0 || j>=cols || temp[i][j]==1 || src>heights[i][j]) return ;
        
        int curr_height=heights[i][j];
        temp[i][j]=1;
        heights[i][j]=INT_MIN;
        for(auto x : directions)
        {
            solve(heights,i+x.first,j+x.second,curr_height,temp);
        }
        heights[i][j]=curr_height;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows=heights.size(),cols=heights[0].size();
        vector<vector<int>>atl(rows,vector<int>(cols,0));
        vector<vector<int>>pac(rows,vector<int>(cols,0));
        vector<vector<int>>ans;

        for(int j=0;j<cols;j++)
        {
            solve(heights,rows-1,j,-1,atl);
            solve(heights,0,j,-1,pac);
        }

        for(int i=0;i<rows;i++)
        {
            solve(heights,i,0,-1,pac);
            solve(heights,i,cols-1,-1,atl);
        }


        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(atl[i][j] && pac[i][j]) ans.push_back({i,j});
            }
            
        }
        return ans;
    }
};
