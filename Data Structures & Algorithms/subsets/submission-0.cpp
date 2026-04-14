class Solution {
public:
    void fun(vector<int>&nums,int i,vector<int>temp,vector<vector<int>>&ans)
    {
        if(i>=nums.size()) 
        {
            ans.push_back(temp);
            return ;
        }
        temp.push_back(nums[i]);
        fun(nums,i+1,temp,ans);
        temp.pop_back();
        fun(nums,i+1,temp,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        fun(nums,0,temp,ans);
        return ans;
    }
};
