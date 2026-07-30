class Solution {
public:
    vector<vector<int>>res;
    void fun(vector<int>&nums,vector<int>&ans,int target,int i)
    {
        if(target==0)
        {
            res.push_back(ans);
            return;
        }
        
        if(i>=nums.size() || target<0) return ;

        ans.push_back(nums[i]);
        fun(nums,ans,target-nums[i],i);
        ans.pop_back();
        fun(nums,ans,target,i+1);
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        res={};
        vector<int>ans;
        fun(nums,ans,target,0);
        return res;
    }
};
