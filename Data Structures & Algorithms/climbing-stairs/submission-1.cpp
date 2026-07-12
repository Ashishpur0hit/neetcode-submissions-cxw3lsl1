class Solution {
public:
    int fun(int n,vector<int>&dp)
    {
        if(n<=3) return n;
        if(dp[n]!=-1) return dp[n];
        dp[n]=fun(n-1,dp)+fun(n-2,dp);
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return fun(n,dp);
    }
};
