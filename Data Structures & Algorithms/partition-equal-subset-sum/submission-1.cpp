class Solution {
public:
    bool fun(vector<int>&nums,int index,int sum,vector<vector<int>>&dp)
    {
        if(index==nums.size())
        {
            if(sum==0) return true;
            else return false;
        }
        if(sum<0) return false;
        if(dp[index][sum]!=-1) return dp[index][sum];

        bool opt1 = fun(nums,index+1,sum-nums[index],dp);
        bool opt2 = fun(nums,index+1,sum,dp);

        dp[index][sum] =  (opt1 || opt2);
        return dp[index][sum];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(auto x : nums) sum+=x;
        if(sum%2!=0) return false;
        vector<vector<int>>dp(nums.size(),vector<int>((sum/2)+1,-1));

        return fun(nums,0,sum/2,dp);
    }
};
