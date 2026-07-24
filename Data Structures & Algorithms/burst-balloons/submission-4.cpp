class Solution {
public:
    int fun(vector<int>&nums,vector<vector<int>>&dp,int left,int right)
    {
        if(left>right) return 0;
        if(dp[left][right]!=-1) return dp[left][right];
        dp[left][right]=0;
        for(int i=left;i<=right;i++)
        {
            int coins = nums[i]*nums[left-1]*nums[right+1] + fun(nums,dp,left,i-1) + fun(nums,dp,i+1,right);
            dp[left][right]=max(dp[left][right],coins);
        }
        return dp[left][right];
    }
    int maxCoins(vector<int>& nums) {
        vector<int>v;
        v.push_back(1);
        for(auto x : nums) v.push_back(x);
        v.push_back(1);
        vector<vector<int>>dp(v.size(),vector<int>(v.size(),-1));
        return fun(v,dp,1,v.size()-2);
    }
};
