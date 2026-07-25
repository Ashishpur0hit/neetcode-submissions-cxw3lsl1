class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<pair<int,int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        pq.push({grid[0][0],0,0});

        while(!pq.empty())
        {
            auto curr = pq.top();
            int t=curr[0],r=curr[1],c=curr[2];
            pq.pop();

            if(r==grid.size()-1 && c==grid[0].size()-1) return t;

            for(auto x : directions)
            {
                int nr=r+x.first,nc=c+x.second;

                if(nr<0 || nc<0 || nr>=grid.size() || nc>=grid[0].size() || vis[nr][nc])
                {
                    continue;
                }
                else
                {
                    vis[nr][nc]=true;
                    pq.push({max(t,grid[nr][nc]),nr,nc});
                }
            }

        }

        return -1;
    }
};
