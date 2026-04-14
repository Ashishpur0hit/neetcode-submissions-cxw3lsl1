class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1,max_amount=INT_MIN;
        while(i<j)
        {
            max_amount=max(max_amount,min(height[i],height[j])*(j-i));
            (height[i]<=height[j])?(i++):(j--);
        }
        return max_amount;
    }
};
