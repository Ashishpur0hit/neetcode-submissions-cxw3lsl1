class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size(),cols=grid[0].size(),time=0;
        queue<pair<int,int>>q;
        vector<pair<int,int>>directions={{1,0},{0,1},{-1,0},{0,-1}};
        int fruits=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j]==1) fruits++;
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        if(q.size()==0) return (fruits)?-1:0;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                pair<int,int> front = q.front();
                q.pop();
                for(auto x : directions)
                {
                    int i = front.first+x.first,j = front.second+x.second;
                    if(i>=0 && i<rows && j>=0 && j<cols && grid[i][j]==1)
                    {
                        grid[i][j]=2;
                        q.push({i,j});
                    }
                }
            }
            time++;
        }

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j]==1) return -1;
            }
        }
        return time-1;
    }
    
};
