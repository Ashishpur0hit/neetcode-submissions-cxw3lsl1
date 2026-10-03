class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n =nums.size(),prev=INT_MAX;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++)
        {
            int target = - nums[i];
            if(nums[i]!=prev)
            {
                int j = i+1,k=n-1,last=INT_MAX;
                while(j<k)
                {
                    if(nums[j]+nums[k]==target && nums[k]!=last)
                    {
                        ans.push_back({nums[i],nums[j],nums[k]}),last=nums[k--];
                    }
                    else if(nums[j]+nums[k]>target ) k--;
                    else j++;
                }
            }
            prev = nums[i];
        }

        return ans;
    }
};
