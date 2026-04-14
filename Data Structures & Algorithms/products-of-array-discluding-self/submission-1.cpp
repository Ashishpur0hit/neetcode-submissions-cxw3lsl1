class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size(),prefix=1,postfix=1;
        vector<int>ans(n);
        ans[0]=prefix;
        for(int i=1;i<n;i++) ans[i]=prefix*nums[i-1],prefix=ans[i];
        for(int i=n-1;i>=0;i--) ans[i]=postfix*ans[i],postfix*=nums[i];
        return ans; 
    }
};
