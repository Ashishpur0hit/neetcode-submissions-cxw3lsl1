class Solution {
public:
    
    int fun(vector<int>& nums,int n,int index,vector<vector<int>>& dp,int buy_index=-1)
    {
        if(index>=n)
        {
            return 0;
        }
        if(dp[index][buy_index+1]!=-1) return dp[index][buy_index+1];
        int opt1,opt2;

        if(buy_index==-1)
        {
            opt1 = fun(nums,n,index+1,dp,index);
            opt2 = fun(nums,n,index+1,dp,buy_index);
            
        }
        else if(nums[index]>nums[buy_index]) 
        {
            opt1 = nums[index]-nums[buy_index]+fun(nums,n,index+2,dp,-1);
            opt2 = fun(nums,n,index+1,dp,buy_index);
        }
        dp[index][buy_index+1] = max(opt1,opt2);
        return dp[index][buy_index+1];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return fun(prices,n,0,dp);
    }
};
