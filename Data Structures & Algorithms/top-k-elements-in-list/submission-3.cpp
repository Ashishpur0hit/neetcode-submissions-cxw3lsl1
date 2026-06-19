class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        unordered_map<int,int>map;
        vector<int>ans;
        for(auto x : nums) map[x]++;
        for(auto x : map) pq.push({x.second,x.first});
        while(k--) ans.push_back(pq.top().second),pq.pop();
        return ans;
    }
};
