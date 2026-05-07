class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>>s;
        int n = temp.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            if(s.empty()) s.push({temp[i],i});
            else 
            {
                while(!s.empty() && s.top().first<temp[i])
                {
                    ans[s.top().second]=i-s.top().second;
                    s.pop();
                }
                s.push({temp[i],i});
            }
        }
        return ans;
    }
};
