class Solution {
public:
    int n1,n2;
    int fun(string &s , string &t ,int i,int j,vector<vector<int>>&dp)
    {
        if(j>=n2) return 1;
        if(i>=n1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j])
        {
            dp[i][j]= fun(s,t,i+1,j+1,dp)+fun(s,t,i+1,j,dp);
            return dp[i][j];
        }
        dp[i][j]= fun(s,t,i+1,j,dp);
        return dp[i][j];
    }
    int numDistinct(string s, string t) {
        n1=s.length(),n2=t.length();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return fun(s,t,0,0,dp);
    }
};
