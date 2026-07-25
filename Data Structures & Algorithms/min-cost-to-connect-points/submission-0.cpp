class Solution {
public:
    
    int findParent(vector<int>& parent,int node)
    {
        if(parent[node]==node) return node;
        return parent[node]=findParent(parent,parent[node]);
    }


    void unionFind(int u,int v, vector<int>& parent,vector<int>& rank)
    {
        u = findParent(parent,u);
        v = findParent(parent,v);

        if(rank[u]==rank[v])
        {
            parent[v]=u;
            rank[v]++;
        }
        else if(rank[u]>rank[v])
        {
            parent[v]=u;
        }
        else parent[u]=v;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<int>parent(n),rank(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
        vector<vector<int>>edges;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int dist = abs(points[j][0]-points[i][0]) + abs(points[j][1]-points[i][1]);
                edges.push_back({dist,i,j});
            }
        }



        sort(edges.begin(),edges.end());
        int ans =0;

        for(int i=0;i<edges.size();i++)
        {
            if(findParent(parent,edges[i][1])!=findParent(parent,edges[i][2]))
            {
                ans+=edges[i][0];
                unionFind(edges[i][1],edges[i][2],parent,rank);
            }
        }

        return ans;



    }
};
