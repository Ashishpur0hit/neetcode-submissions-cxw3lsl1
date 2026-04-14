class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(!nums.size()) return 0;
        set<int>s(nums.begin(),nums.end());
        int ans=0,maxi=0,prev=INT_MIN;
        for(auto x : s) 
        {
            if(x-prev==1)ans++;
            else if(x-prev==0) continue;
            else maxi=max(maxi,ans),ans=0;
            prev=x;
        }
        maxi=max(maxi,ans);
        return maxi+1;
    }
};
