class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string ,vector<string>>map;
        vector<vector<string>>ans;
        for(auto x : strs)
        {
            string str = x;
            sort(str.begin(),str.end());
            map[str].push_back(x);
        }
        for(auto x : map)
        {
            ans.push_back(x.second);
        }
        return ans;

    }
};
