class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int left,right,n = heights.size(),curr_height,curr_width,max_area=0;
        for(int i=0;i<n;i++)
        {
            curr_height = heights[i];
            left=i,right=i;
            while(left>=0 && heights[left]>=curr_height) left--;
            while(right<n && heights[right]>=curr_height) right++;
            curr_width = right- (left+1);
            max_area = max(max_area,curr_height*curr_width);
        }
        return max_area;
    }
};
