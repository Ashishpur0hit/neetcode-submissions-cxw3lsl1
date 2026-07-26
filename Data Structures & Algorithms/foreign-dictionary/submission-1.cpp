class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int n=words.size();
        unordered_map<char,set<char>>adj;
        unordered_map<char,int>indegree;


        for(auto x : words) 
        {
            for(auto c : x) indegree[c]=0;
        }

        for(int x=0;x<n-1;x++)
        {
            string str1 = words[x],str2=words[x+1];
            int i=0,j=0;
            while(i<str1.length() && j<str2.length())
            {
                if(str1[i]!=str2[j]) 
                {
                    if(adj[str1[i]].insert(str2[j]).second)
                    indegree[str2[j]]++;
                    break;
                }

                i++,j++;
            }

            if(j>=str2.length() && i<str1.length()) return "";
        }

        queue<char>q;
        string ans;
        for(auto x : indegree) if(x.second==0) q.push(x.first);

        while(!q.empty())
        {
            char front = q.front();
            ans.push_back(front);
            q.pop();

            for(auto x : adj[front])
            {
                indegree[x]--;
                if(indegree[x]==0) q.push(x);
            }
        }
        if(ans.size()==indegree.size()) return ans;

        return "";


    }
};
