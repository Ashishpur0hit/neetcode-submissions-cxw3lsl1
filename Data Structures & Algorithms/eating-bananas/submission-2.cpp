class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size(), maxi=0 ,start=1,end;
        for(auto x : piles) maxi = max(maxi,x);
        end=maxi;
        while(start<end)
        {
            int mid = (end-start)/2+start;
            int hours=0;
            for(int i=0;i<n;i++)
            {
                if(piles[i]<mid) hours++;
                else 
                {
                    hours+=piles[i]/mid;
                    if(piles[i]%mid) hours++;
                }
            }
            cout<<mid<<" "<<hours<<endl;
            if(hours<=h) end=mid;
            else start=mid+1;
        }
        return end;
    }
};
