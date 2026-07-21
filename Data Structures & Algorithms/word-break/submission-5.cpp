class Solution {
public:
    bool dfs(string &s,vector<string>&wordDict,int index,vector<int>&dp)
    {
        if(index>=s.length()) return true;
        if(dp[index]!=-1) return dp[index];
        for(auto x : wordDict)
        {
            if(index+x.length()<=s.length() && s.substr(index,x.length())==x)
            {
                bool ans = dfs(s,wordDict,index+x.length(),dp);
                if(ans) 
                {
                    dp[index]=1;
                    return true;
                }
            }

        }
        dp[index]=0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.length(),-1);
        return dfs(s,wordDict,0,dp);
    }
};
