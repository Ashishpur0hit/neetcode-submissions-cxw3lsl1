class Solution {
public:
    bool canfinishPile(vector<int>&piles,int h,int rate)
    {
        int time=0;
        for(auto x : piles)
        {
            if(x<rate) time++;
            else
            {
                time+=(x/rate);
                if(x%rate) time++;
            }
        }
        cout<<rate<<" "<<time<<endl;
        return (time<=h)?true:false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size(),maxi=piles[0],left=1,right;
        for(auto x : piles) maxi=max(maxi,x);
        right=maxi;
        while(left<right)
        {
            int mid = left+((right-left)/2);
            if(canfinishPile(piles,h,mid)) right=mid;
            else left=mid+1;
        }
        return right;

    }
};
