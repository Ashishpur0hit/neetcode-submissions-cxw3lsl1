class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size() , start=0 , end =n-1;
        while(start<=end)
        {
            int mid = (end-start)/2+start;
            if(nums[mid]==target) return mid;
            if(target<=nums[n-1])
            { 
                if(nums[mid]>target)
                {
                    (nums[mid]<=nums[n-1])?(end=mid-1):(start=mid+1);
                }
                else start=mid+1;
            }
            else
            {
                if(nums[mid]<target)
                {
                    (nums[mid]<=nums[n-1])?(end=mid-1):(start=mid+1);
                }
                else end=mid-1;
            }
        }
        return -1;
    }
};
