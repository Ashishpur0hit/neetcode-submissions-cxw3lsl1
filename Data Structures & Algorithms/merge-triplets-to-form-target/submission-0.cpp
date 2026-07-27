class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        vector<bool>ans(3,false);
        for(int i=0;i<n;i++)
        {
            vector<int>curr = triplets[i];
            if(curr[0]==target[0] && curr[1]<=target[1] && curr[2]<=target[2]) ans[0]=true;
            if(curr[1]==target[1] && curr[0]<=target[0] && curr[2]<=target[2]) ans[1]=true;
            if(curr[2]==target[2] && curr[1]<=target[1] && curr[0]<=target[0]) ans[2]=true;
        }
        for(auto x : ans) if(!x) return false;
        return true;
    }
};
