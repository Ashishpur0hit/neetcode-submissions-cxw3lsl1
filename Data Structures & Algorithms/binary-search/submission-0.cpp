class Solution {
public:
    int fun(vector<int>&nums,int target,int start,int end)
    {
        while(start<=end)
        {
            int mid = (start+end)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) end=mid-1;
            else start=mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        if(nums.size()==1)
        {
            return (nums[0]==target) ? 0 : -1;
        }
        return fun(nums,target,0,nums.size()-1);
    }
};
