class Solution {
public:
    int n;
    int fun(vector<int>&nums,int left,int right,vector<vector<int>>&dp)
    {
        if(left==right) return 0;
        if(dp[left][right]!=-1) return dp[left][right];
        int max_coins=0;
        for(int i=left+1;i<right;i++)
        {
            max_coins = max(max_coins,fun(nums,left,i,dp) + fun(nums,i,right,dp) + (nums[left]*nums[i]*nums[right]));
        }
        dp[left][right]= max_coins;
        return dp[left][right];
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return fun(nums,0,n-1,dp);
    }
};
