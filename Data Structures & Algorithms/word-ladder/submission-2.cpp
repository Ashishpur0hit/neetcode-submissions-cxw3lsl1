class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(),wordList.end(),endWord)==wordList.end() || beginWord==endWord) return 0;
        unordered_map<int,vector<int>>adj;
        unordered_map<int,string>map;
        int n = wordList.size(),m = beginWord.length();
        for(int i=0;i<n;i++)
        {
            map[i]=wordList[i];
        }

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int count=0;
                for(int k=0;k<m;k++)
                {
                    if(wordList[i][k]!=wordList[j][k]) count++;
                }

                if(count==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        queue<int>q;
        vector<bool>vis(n,false);

        for(int i=0;i<n;i++)
        {
            int count=0;
            for(int j=0;j<m;j++)
            {
                if(beginWord[j]!=wordList[i][j]) count++;
            }
            if(count==1) q.push(i),vis[i]=true;
        }

        int transitions = 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int front = q.front();
                if(map[front]==endWord) return transitions+2;
                q.pop();

                for(auto x : adj[front])
                {
                    if(!vis[x])
                    {
                        vis[x]=true;
                        q.push(x);
                    }
                }
                
            }

            transitions++;
        }

        return 0;
        

    }
};
