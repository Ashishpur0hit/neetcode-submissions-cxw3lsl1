class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.size()==1) return {nums[0]};
        unordered_map<int,int>map;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>min_heap;
        vector<int>ans;
        for(auto x : nums) map[x]++;
        for(auto pair : map)
        {
            if(min_heap.size()<k)
            {
                min_heap.push({pair.second,pair.first});
            }
            else 
            {
                if(pair.second>min_heap.top().first) 
                {
                    min_heap.pop();
                    min_heap.push({pair.second,pair.first});
                }
            }
        }
        while(!min_heap.empty()) ans.push_back(min_heap.top().second) , min_heap.pop();
        return ans;
    }
};
