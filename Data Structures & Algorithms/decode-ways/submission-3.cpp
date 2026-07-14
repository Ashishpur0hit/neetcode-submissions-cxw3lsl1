class Solution {
public:
    int fun(string s,int n,int index,vector<int>&dp)
    {
        if(index==n) return 1;
        if(s[index]=='0') return 0;
        if(dp[index]!=-1) return dp[index];
        int ways = fun(s,n,index+1,dp);

        if(index+1 < n)
        {
            int num = (s[index]-'0')*10 + s[index+1]-'0';
            if(num>=1 && num <=26)
            {
                ways += fun(s,n,index+2,dp);
            }
        }

        dp[index]=ways;
        return dp[index];
    }
    int numDecodings(string s) {
        int n = s.length();
        vector<int>dp(n,-1);
        return fun(s,n,0,dp);
    }
};
