class Solution {
public:
    bool detectCycle(unordered_map<int,vector<int>>&adj,vector<bool>&vis,int src,int parent)
    {
        vis[src]=true;
        bool ans = false;
        for(auto x : adj[src])
        {
            if(vis[x] && x!=parent)    return true;
            else if(!vis[x])
            {
                ans  = ans || detectCycle(adj,vis,x,src);
                if(ans) return ans;
            }
        }
        return ans;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        vector<bool>vis(n,false);
        for(auto x : edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }

        bool ans = detectCycle(adj,vis,0,-1);

        for(auto x : vis) if(!x) return false;
        return (ans)?false:true;
    }
};
