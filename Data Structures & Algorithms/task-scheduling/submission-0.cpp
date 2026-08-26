class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>count(26,0);
        for(auto x : tasks)
        {
            count[x-'A']++;
        }


        priority_queue<int>max_heap;
        for(auto x : count) if(x>0) max_heap.push(x);

        queue<pair<int,int>>q;
        int time=0;

        while(!max_heap.empty() || !q.empty())
        {
            time++;
            if(!max_heap.empty())
            {
                int cnt = max_heap.top()-1;
                max_heap.pop();
                if(cnt>0)
                {
                    q.push({cnt,time+n});
                }
            }

            if(!q.empty() && q.front().second==time) 
            {
                max_heap.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};
