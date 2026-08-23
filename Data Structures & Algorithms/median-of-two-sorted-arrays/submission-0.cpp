class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(),n=nums2.size();
        vector<int>v(m+n);
        int i=m-1,j=n-1,k=m+n-1;
        while(i>=0 && j>=0)
        {
            if(nums1[i]>=nums2[j]) v[k--]=nums1[i--];
            else v[k--]=nums2[j--];
        }
        while(i>=0) v[k--]=nums1[i--];
        while(j>=0) v[k--]=nums2[j--];

        for(auto x : v) cout<<x<<" ";
        cout<<endl;
        if((m+n)%2==0)
        {
            double start = v[((m+n)/2)-1],end=v[(m+n)/2];

            cout<<start<<" "<<end<<endl;
            return start + ((end-start)/2);
        }
        return v[(m+n)/2];
    }
};
