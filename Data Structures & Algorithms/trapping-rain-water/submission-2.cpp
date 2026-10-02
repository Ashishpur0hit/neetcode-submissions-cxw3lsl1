class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>l_max,r_max;
        int left_max= height[0],right_max = height[n-1],total_water=0;
        for(int i=0;i<n;i++)
        {
            left_max = max(left_max,height[i]);
            l_max.push_back(left_max);
        }
        for(int i=n-1;i>=0;i--)
        {
            right_max = max(right_max,height[i]);
            r_max.push_back(right_max);
        }
        reverse(r_max.begin(),r_max.end());
        for(int i=0;i<n;i++)
        {
            total_water+=min(l_max[i],r_max[i])-height[i];
        }
        return total_water;

    }
};
