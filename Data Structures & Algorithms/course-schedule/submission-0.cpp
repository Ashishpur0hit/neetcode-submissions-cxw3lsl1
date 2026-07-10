class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //create an adjacency list
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(numCourses,0);
        queue<int>q;
        vector<int>ans;
        for(auto x : prerequisites)
        {
            adj[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        } 
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty())
        {
            int front = q.front();
            ans.push_back(front);
            q.pop();
            for(auto x : adj[front])
            {
                indegree[x]--;
                if(indegree[x]==0) q.push(x);
            }
        }
        return (ans.size()==numCourses)?true:false;

    }
};
