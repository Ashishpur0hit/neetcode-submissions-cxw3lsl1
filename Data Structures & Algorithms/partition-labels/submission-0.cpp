class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.length(),index=0;
        unordered_map<char,int>map;
        queue<char>q;
        vector<int>ans;

        for(auto x : s) map[x]++;
        
        
        while(index<n)
        {
            map[s[index]]--;
            q.push(s[index++]);
            
            int size=0;
            while(!q.empty())
            {
                char front = q.front();
                q.pop();

                while(map[front])
                {
                    map[s[index]]--;
                    if(s[index]!=front) q.push(s[index]);
                    size++;
                    index++;
                }
            }
            ans.push_back(size+1);
        }
        return ans;
    }
};
