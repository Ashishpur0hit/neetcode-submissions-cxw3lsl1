class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&adj,vector<bool>&vis,int src)
    {
        vis[src]=true;
        for(auto x : adj[src])
        {
            if(!vis[x]) dfs(adj,vis,x);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        vector<bool>vis(n,false);
        int components=0;


        for(auto x : edges)
        {
            adj[x[1]].push_back(x[0]);
            adj[x[0]].push_back(x[1]);
        }

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                components++;
                dfs(adj,vis,i);
            }
        }

        return components;
    }
};
