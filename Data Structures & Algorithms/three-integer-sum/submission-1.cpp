class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int prev=INT_MAX,first_prev=INT_MAX;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=first_prev)
            {
                int j=i+1,k=nums.size()-1,target=-nums[i];
                prev=INT_MAX;
                while(j<k)
                {
                    if(nums[j]+nums[k]==target and nums[k]!=prev) ans.push_back({nums[i],nums[j],nums[k]}),prev=nums[k--];
                    else if(nums[j]+nums[k]<target) j++;
                    else k--;
                }
                first_prev=nums[i];
            }
            
        }
        return ans;
    }
};
