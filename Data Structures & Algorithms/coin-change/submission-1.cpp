class Solution {
public:
    int fun(vector<int>&coins,int amount,vector<int>&dp)
    {
        if(amount<0) return 10001;
        if(amount==0) return 0;
        if(dp[amount]!=-1) return dp[amount];
        int mini = 10001;

        for(int i=0;i<coins.size();i++)
        {
            mini = min(mini,1+fun(coins,amount-coins[i],dp));
        }
        dp[amount]=mini;
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int ans = fun(coins,amount,dp);
        return (ans!=10001)?ans:-1;
    }
};
