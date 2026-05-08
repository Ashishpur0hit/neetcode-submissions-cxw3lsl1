class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        stack<pair<int,int>>s;
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            if(s.empty()) s.push({temp[i],i});
            else 
            {
                while(!s.empty() && temp[i]>s.top().first)
                {
                    ans[s.top().second] = i-s.top().second;
                    s.pop();
                }
                s.push({temp[i],i});
            }
        }
        return ans;
    }
};
