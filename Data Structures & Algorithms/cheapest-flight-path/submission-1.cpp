class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto x : flights)
        {
            adj[x[0]].push_back({x[1],x[2]});
        }
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        queue<pair<int,int>>q;
        q.push({src,dist[src]});
        int visited=0,cost=INT_MAX;

        while(!q.empty())
        {
            
            
            int size=q.size();
            

            while(size--)
            {
                int curr_node = q.front().first, curr_dist = q.front().second;
                if(curr_node==dst && visited <k+2) cost = min(cost,curr_dist);
                q.pop();

                for(auto x : adj[curr_node])
                {
                    int new_dist = curr_dist+x.second;
                    if(dist[x.first]>new_dist)
                    {
                        dist[x.first]=new_dist;
                        q.push({x.first,new_dist});
                    }
                }
            }

            visited++;

        }


        return (cost==INT_MAX)?-1:cost;
        
    }
};
