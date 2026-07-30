class Solution {
public:
    vector<vector<int>>res;
    void fun(vector<int>&nums,int index)
    {
        if(index>=nums.size())
        {
            res.push_back(nums);
            return;
        }


        for(int i=index;i<nums.size();i++)
        {
            swap(nums[i],nums[index]);
            fun(nums,index+1);
            swap(nums[i],nums[index]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        res=vector<vector<int>>(0);
        fun(nums,0);
        return res;
    }
};
