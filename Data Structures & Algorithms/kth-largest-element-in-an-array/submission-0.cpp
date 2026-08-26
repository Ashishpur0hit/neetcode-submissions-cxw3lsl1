class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>min_heap;
        for(auto x : nums)
        {
            if(min_heap.size()<k) min_heap.push(x);
            else if(x>min_heap.top())
            {
                min_heap.push(x);
                min_heap.pop();
            }
        }
        return min_heap.top();
    }
};
