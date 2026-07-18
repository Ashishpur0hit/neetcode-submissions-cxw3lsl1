class Solution {
public:
    int fun(vector<int>& nums,int index,int prev_index,vector<vector<int>>&dp)
    {
        if(index>=nums.size()) return 0;
        if(dp[index][prev_index+1]!=-1) return dp[index][prev_index+1];
        int opt1,opt2;
        if(prev_index==-1 || nums[index]>nums[prev_index])
        {
            opt1=1+fun(nums,index+1,index,dp);
            opt2=fun(nums,index+1,prev_index,dp);
        }
        else
        {
            opt1=0;
            opt2=fun(nums,index+1,prev_index,dp);
        }
        dp[index][prev_index+1]= max(opt1,opt2);
        return dp[index][prev_index+1];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));

        return fun(nums,0,-1,dp);
    }
};
