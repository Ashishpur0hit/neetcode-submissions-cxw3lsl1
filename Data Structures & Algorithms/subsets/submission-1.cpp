class Solution {
public:
    vector<vector<int>>res;
    void fun(vector<int>&nums,vector<int>&ans,int i)
    {
        if(i>=nums.size()) 
        {
            res.push_back(ans);
            return ;
        }

        ans.push_back(nums[i]);
        fun(nums,ans,i+1);
        ans.pop_back();
        fun(nums,ans,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        res = {};
        vector<int>ans;
        fun(nums,ans,0);
        return res;
    }
};
