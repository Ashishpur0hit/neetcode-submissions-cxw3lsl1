class Solution {
public:
    bool dfs(unordered_map<string,vector<string>>&adj,vector<string>&res,string src,int len)
    {
        if(res.size()==len) return true;
        if(adj.find(src)==adj.end()) return false;

        vector<string> airports = adj[src];
        for(int i=0;i<airports.size();i++)
        {
            string x = airports[i];
            res.push_back(x);
            adj[src].erase(adj[src].begin()+i);
            if(dfs(adj,res,x,len)) return true;
            res.pop_back();
            adj[src].insert(adj[src].begin()+i,x);
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>>adj;
        for(auto x : tickets ) adj[x[0]];
        sort(tickets.begin(),tickets.end());
        for(auto x : tickets ) adj[x[0]].push_back(x[1]);

        vector<string>res ={"JFK"};
        dfs(adj,res,"JFK",tickets.size()+1);
        return res;
    }
};
