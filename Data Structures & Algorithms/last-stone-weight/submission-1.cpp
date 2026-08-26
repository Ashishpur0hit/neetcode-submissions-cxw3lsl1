class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int>pq;
        for(auto x : stones)
        {
            pq.push(x);
        }

        while(!pq.empty())
        {
            if(pq.size()==1)
            {
                return pq.top();
            }
            int a = pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            if(a!=b) pq.push(abs(a-b));            
        }
        return 0;
    }
};
