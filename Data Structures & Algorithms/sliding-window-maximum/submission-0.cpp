class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>>max_heap;
        vector<int>ans;
        for(int i=0;i<k;i++) max_heap.push({nums[i],i});
        ans.push_back(max_heap.top().first);
        for(int i=k;i<n;i++)
        {
            max_heap.push({nums[i],i});
            while(max_heap.top().second<=i-k) max_heap.pop();
            ans.push_back(max_heap.top().first);
        }
        return ans;


    }
};
