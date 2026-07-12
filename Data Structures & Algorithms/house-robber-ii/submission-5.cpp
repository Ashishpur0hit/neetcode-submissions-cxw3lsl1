class Solution {
public:
    int fun(vector<int>&nums,vector<vector<int>>&dp,int index,bool flag)
    {
        if(index>=nums.size() || (flag && index==nums.size()-1)) return 0;
        if(dp[index][flag]!=-1) return dp[index][flag];
        dp[index][flag] = max(nums[index]+fun(nums,dp,index+2,flag),fun(nums,dp,index+1,flag));
        return dp[index][flag];
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<vector<int>>dp(nums.size(),vector<int>(2,-1));
        return max(fun(nums,dp,0,true),fun(nums,dp,1,false));
    }
};
