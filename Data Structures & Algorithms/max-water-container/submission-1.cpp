class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=height.size()-1,max_amount=0;
        while(left<right)
        {
            max_amount=max(max_amount,min(height[left],height[right])*(right-left));
            height[left]<=height[right] ? (left++) : (right--);
        }
        return max_amount;
    }
};
