class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<float,vector<int>>>temp;
        vector<vector<int>>ans;
        for(auto x : points)
        {
            float dist = sqrt(pow(x[0],2)+pow(x[1],2));
            temp.push_back({dist,x});
        }
        sort(temp.begin(),temp.end());
        int index=0;
        while(k--)
        {
            ans.push_back(temp[index].second);
            index++;
        }
        return ans;
    }
};
