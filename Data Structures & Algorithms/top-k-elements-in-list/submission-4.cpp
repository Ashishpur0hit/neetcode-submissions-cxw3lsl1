class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>map;
        priority_queue<pair<int,int>>max_heap;
        vector<int>ans;
        for(auto x : nums) map[x]++;
        for(auto x : map) max_heap.push({x.second,x.first});
        while(k--) ans.push_back(max_heap.top().second),max_heap.pop();
        return ans;
    }
};
