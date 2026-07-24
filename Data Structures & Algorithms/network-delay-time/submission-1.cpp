class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<vector<int>>>adj;
        vector<int>dis(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto x : times)
        {
            adj[x[0]].push_back({x[1],x[2]});
        }
        dis[k]=0;
        pq.push({0,k});

        while(!pq.empty())
        {
            int curr_dist = pq.top().first;
            int curr_node = pq.top().second;
            pq.pop();
            if(curr_dist<=dis[curr_node])
            {
                for(auto x : adj[curr_node])
                {
                    int dest = x[0],weight=x[1];
                    int new_dist = curr_dist+weight;
                    if(new_dist<dis[dest])
                    {
                        dis[dest] = new_dist;
                        pq.push({dis[dest],dest});
                    }
                    
                }
            }
        }

        int ans = 0;
        for(int i=1;i<=n;i++) 
        {
            if(dis[i]==INT_MAX) return -1;
            cout<<dis[i]<<" ",ans = max(ans,dis[i]);
        }

        return ans;
    }
};
