class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size() , col = grid[0].size(),time=0;
        vector<pair<int,int>>directions={{1,0},{0,1},{-1,0},{0,-1}};
        queue<pair<int,int>>q;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                pair<int,int>front=q.front();
                q.pop();
                int i=front.first,j=front.second;

                for(auto x : directions)
                {
                    if(i+x.first<0 || i+x.first>=row || j+x.second<0 || j+x.second>=col || grid[i+x.first][j+x.second]!=1) continue;
                    else 
                    {
                        grid[i+x.first][j+x.second]=2;
                        q.push({i+x.first,j+x.second});
                    }
                }
            }
            time++;
        }
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]==1) return -1;
            }
        }
        return (time)?time-1:time;

    }
};
