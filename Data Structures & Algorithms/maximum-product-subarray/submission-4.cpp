class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int curr_min = 1,curr_max =1;
        int res = INT_MIN;
        for(auto x : nums)
        {
            int temp = curr_max*x;
            curr_max = max(curr_max*x,max(curr_min*x,x));
            curr_min = min(temp,min(curr_min*x,x));
            res = max(res,curr_max);
        }
        return res;
    }
};
