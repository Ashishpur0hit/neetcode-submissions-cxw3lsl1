class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        int i=0,max_i=0,jumps=0,max_val=0;
        
        while(i+nums[i]<n-1)
        {
            max_val=-1,max_i=-1;
            for(int j=i+1;j<=i+nums[i];j++)
            {
                if(nums[j]+j>=max_val) max_val=nums[j]+j,max_i=j;
            }
            
            jumps++;
            i=max_i;

        }
        return jumps+1;
    }
};
