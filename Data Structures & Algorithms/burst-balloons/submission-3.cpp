class Solution {
public:
    int fun(vector<int>&nums,int l,int r,vector<vector<int>>&dp)
    {
        if(l>r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int max_coins=0;
        for(int i=l;i<=r;i++)
        {
            int coins = nums[l-1]*nums[i]*nums[r+1]+fun(nums,i+1,r,dp)+fun(nums,l,i-1,dp);
            max_coins = max(max_coins,coins);
        }
        dp[l][r]= max_coins;
        return dp[l][r];
    }
    int maxCoins(vector<int>& nums) {
        vector<int>newNums;
        newNums.push_back(1);
        for(auto x : nums) newNums.push_back(x);
        newNums.push_back(1);
        vector<vector<int>>dp(nums.size()+2,vector<int>(nums.size()+2,-1));
        return fun(newNums,1,newNums.size()-2,dp);
    }
};
