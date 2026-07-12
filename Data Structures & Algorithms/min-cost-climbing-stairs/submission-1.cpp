class Solution {
public:
    int fun(vector<int>& cost,int index,vector<int>&dp)
    {
        if(index>=cost.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        dp[index]=cost[index]+min(fun(cost,index+1,dp),fun(cost,index+2,dp));
        return dp[index];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n,-1);
        return min(fun(cost,0,dp),fun(cost,1,dp));
    }
};
