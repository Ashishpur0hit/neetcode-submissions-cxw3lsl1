class Solution {
public:
    int fun(vector<int>&nums,int index,vector<int>&dp)
    {
        if(index>=nums.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        dp[index]= max(nums[index]+fun(nums,index+2,dp),fun(nums,index+1,dp));
        return dp[index];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);

        return fun(nums,0,dp);
    }
};
