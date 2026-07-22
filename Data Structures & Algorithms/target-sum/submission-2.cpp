class Solution {
public:
    int fun(vector<int>&nums,int n,int target,int index)
    {
        if(target==0) return 1;
        if(index>=n) return 0;

        int opt1,opt2;

        if(2*nums[index]>target)
        {
            opt1 = 0;
            opt2 = fun(nums,n,target,index+1);
        }
        else
        {
            opt1 = fun(nums,n,target-2*nums[index],index+1);
            opt2 = fun(nums,n,target,index+1);
        }

        return opt1+opt2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total_sum=0,zeroes = 0;
        for(auto x : nums) 
        {
            total_sum+=x;
            if(!x) zeroes++;
        }

        if(total_sum==target)
        {
            if(zeroes)
            {
                return pow(2,zeroes);
            }
            return 1;
        }
        return fun(nums,n,total_sum-target,0);
    }
};
