class Solution {
public:
    bool isNStraightHand(vector<int>& hands, int groupSize) {
        int n= hands.size(),groups =n/groupSize;
        if(n%groupSize) return false;
        sort(hands.begin(),hands.end());
        vector<int>vis(n,0);
        for(int i=0;i<groups;i++)
        {
            int count = groupSize,prev=-1;
            for(int i=0;i<n;i++)
            {
                if((prev==-1 && vis[i]==0) || (hands[i]-prev==1 && vis[i]==0)) 
                {
                    cout<<hands[i]<<" ";
                    prev=hands[i];
                    vis[i]=1;
                    count--;
                }
                if(!count) break;
            }

            if(count) return false;
        }
        return true;

    }
};
