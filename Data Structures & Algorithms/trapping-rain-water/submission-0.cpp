class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size(),lmaxi=0,rmaxi=0,sum=0;
        vector<int>lmax(n),rmax(n);
        for(int i=0;i<n;i++)
        {
            lmaxi=max(lmaxi,height[i]);
            lmax[i]=lmaxi;
        }
        for(int i=n-1;i>=0;i--)
        {
            rmaxi=max(rmaxi,height[i]);
            rmax[i]=rmaxi;
        }
        for(int i=0;i<n;i++)
        {
            sum+=min(lmax[i],rmax[i])-height[i];
        }
        return sum;
    }
};
