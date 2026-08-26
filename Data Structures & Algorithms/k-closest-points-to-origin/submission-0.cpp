class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<float,vector<float>,greater<float>>pq;
        unordered_map<float,vector<vector<int>>>map;
        vector<vector<int>>ans;
        for(auto x : points)
        {
            float dist = sqrt(pow(x[0],2) + pow(x[1],2));
            pq.push(dist);
            map[dist].push_back(x);
        }

        while(k--)
        {
            float key = pq.top();
            int n = map[key].size();
            ans.push_back(map[key][n-1]);
            map[key].pop_back();
            pq.pop();
        }
        return ans;
    }
};
