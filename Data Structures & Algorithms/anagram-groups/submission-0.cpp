class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size()==1) return {{strs[0]}};
        unordered_map<string,vector<int>>map;
        vector<vector<string>>ans;
        for(int i=0;i<strs.size();i++)
        {
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            map[temp].push_back(i);
        }
        for(auto x : map)
        {
            vector<string> temp={};
            for(auto ind : x.second)
            {
                temp.push_back(strs[ind]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
