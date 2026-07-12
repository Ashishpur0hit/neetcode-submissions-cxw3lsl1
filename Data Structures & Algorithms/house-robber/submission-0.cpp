class Solution {
public:
    int fun(vector<int>&nums,vector<int>&dp,int index)
    {
        if(index>=nums.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        dp[index]=nums[index]+max(fun(nums,dp,index+2),fun(nums,dp,index+3));
        return dp[index];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return max(fun(nums,dp,0),fun(nums,dp,1));
    }
};
