class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size(),start=0,end=n-1;
        bool first_plane = (target>nums[n-1])?true:false;
        while(start<=end)
        {
            int mid= (start+end)/2;
            if(nums[mid]==target) return mid;
            else if(first_plane and nums[mid]>target) end =mid-1;
            else if(!first_plane and nums[mid]>target)
            {
                (nums[mid]>nums[n-1])?(start=mid+1):(end=mid-1);
            }
            else if(first_plane and nums[mid]<target)
            {
                (nums[mid]<=nums[n-1])?(end=mid-1):(start=mid+1);
            }
            else start=mid+1;
        }
        return -1;
    }
};
