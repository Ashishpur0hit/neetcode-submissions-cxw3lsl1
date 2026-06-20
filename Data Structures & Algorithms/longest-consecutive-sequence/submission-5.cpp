class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size(),ans=1,curr_size=1;
        if(!n) return 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++)
        {
            if(nums[i+1]-nums[i]==1) curr_size++;
            else if(nums[i+1]-nums[i]==0) continue;
            else 
            {
                ans=max(ans,curr_size);
                curr_size=1;
            }
        }
        ans=max(ans,curr_size);
        return ans;
    }
};
