class Solution {
public:
    int findMin(vector<int> &nums) {
        int n=nums.size(),start=0,end=n-1;
        while(start<end)
        {
            int mid = (end-start)/2+start;
            if(nums[mid]<nums[n-1]) end=mid;
            else start=mid+1;
        }
        return nums[end];
    }
};
