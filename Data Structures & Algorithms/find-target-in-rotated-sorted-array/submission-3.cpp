class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(),left=0,right=n-1;
        while(left<=right)
        {
            int mid = left+((right-left)/2);
            if(nums[mid]==target) return mid;
            else if(target<=nums[n-1])
            {
                if(nums[mid]<=nums[n-1])
                {
                    //same sorted 2nd portion
                    if(nums[mid]>target) right=mid-1;
                    else left=mid+1; 
                }
                else 
                {
                    // different portions
                    left=mid+1;
                }
            }
            else
            {
                if(nums[mid]>nums[n-1])
                {
                    // same first portion
                    if(nums[mid]>target) right=mid-1;
                    else left=mid+1;
                }
                else right=mid-1;
            }
        }
        return -1;
    }
};
