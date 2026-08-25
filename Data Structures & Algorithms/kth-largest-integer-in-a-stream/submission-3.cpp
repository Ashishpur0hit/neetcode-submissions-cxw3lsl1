class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto x : nums)
        {
            if(pq.size()<k)
            {
                pq.push(x);   
            }
            else 
            {
                if(pq.top()<x) pq.push(x),pq.pop();
            }

        }
    }
    
    int add(int val) {
        if(pq.size()==k)
        {
            if(pq.top()<val)
            {
                pq.pop();
                pq.push(val);
            }
            return pq.top();
        }

        else pq.push(val);
        return pq.top();
    }
};
