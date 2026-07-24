class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size(), curr_sum=0, max_sum=INT_MIN;
        for(auto x : nums)
        {
            curr_sum+=x;
            max_sum=max(curr_sum,max_sum);
            if(curr_sum<0) curr_sum=0;
        }
        return max_sum;
    }
};
