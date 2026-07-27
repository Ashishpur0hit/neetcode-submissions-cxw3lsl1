class Solution {
public:

    int findParent(vector<int>& parent,int node)
    {
        if(parent[node]==node) return node;
        return parent[node]=findParent(parent,parent[node]);
    }


    void unionFind(vector<int>& rank,vector<int>& parent,int u,int v)
    {
        u = findParent(parent,u);
        v = findParent(parent,v);

        if(rank[u]==rank[v])
        {
            parent[v]=u;
            rank[u]++;
        }
        else if(rank[u]>rank[v])
        {
            parent[v]=u;
        }
        else parent[u]=v;

    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(),min_cost=0;
        vector<vector<int>>edges;
        vector<int>parent(n);
        vector<int>rank(n,0);

        for(int i=0;i<n;i++) parent[i]=i;

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int dist = abs(points[j][0]-points[i][0]) + abs(points[j][1]-points[i][1]);
                edges.push_back({dist,i,j});
            }
        }

        sort(edges.begin(),edges.end());

        for(auto x : edges)
        {
            auto curr = x;
            int curr_dist = curr[0] , src = curr[1] , dest = curr[2];

            if(findParent(parent,src)!=findParent(parent,dest))
            {
                min_cost+=curr_dist;
                unionFind(rank,parent,src,dest);
            }
        }

        return min_cost;
    }
};