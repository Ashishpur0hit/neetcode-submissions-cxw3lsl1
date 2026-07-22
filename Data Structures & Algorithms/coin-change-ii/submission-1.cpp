class Solution {
public:
    int fun(vector<int>&coins,int n,int amount,int index,vector<vector<int>>&dp)
    {
        if(amount==0) return 1;
        if(index>=n) return 0;
        if(dp[amount][index]!=-1) return dp[amount][index];
        int opt1,opt2;

        if(coins[index]>amount)
        {
            opt1 = 0;
            opt2 = fun(coins,n,amount,index+1,dp);
        }
        else
        {
            opt1 = fun(coins,n,amount-coins[index],index,dp);
            opt2 = fun(coins,n,amount,index+1,dp);
        }

        dp[amount][index] =  opt1+opt2;
        return dp[amount][index];
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(amount+1,vector<int>(n,-1));
        return fun(coins,n,amount,0,dp);
    }
};
