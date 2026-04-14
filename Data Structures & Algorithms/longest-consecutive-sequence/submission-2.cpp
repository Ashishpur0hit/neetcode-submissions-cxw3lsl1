class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size()) return 0;
        sort(nums.begin(),nums.end());
        int temp=0,ans=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            cout<<nums[i+1]<<" "<<nums[i]<<endl;
            if(nums[i+1]-nums[i]==0) continue;
            else if(nums[i+1]-nums[i]==1)temp++;
            else ans=max(ans,temp),temp=0;
        }
        ans=max(ans,temp);
        return ans+1;
    }
};
