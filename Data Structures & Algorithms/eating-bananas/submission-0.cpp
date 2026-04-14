class Solution {
public:
    int binarySearch(vector<int>& piles,int h,int start,int end)
    {
        while(start<end)
        {
            int mid=(start+end)/2;
            int hours=0;
            for(int i=0;i<piles.size();i++)
            {
                if(piles[i]<mid) hours++;
                else 
                {
                    hours+=piles[i]/mid;
                    if(piles[i]%mid) hours++;
                }
            }
            if(hours<=h) end=mid;
            else start=mid+1;
        }
        return end;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_ele=0,min_k;
        for(auto x:piles) max_ele=max(max_ele,x);
        return binarySearch(piles,h,1,max_ele);
    }
};
