class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        int count=1,max_len=1;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[i-1]) continue;
            else if(nums[i]-nums[i-1]==1) count++;
            else 
            {
                max_len = max(max_len,count);
                count=1;
            }
        }
        max_len = max(max_len,count);
        return max_len;
    }
};
