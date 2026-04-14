class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map<string,vector<string>>map;
        vector<vector<string>>ans;
        for(int i=0;i<n;i++)
        {
            int arr[26]={0};
            for(auto x : strs[i]) arr[x-'a']++;

            string key = "";
            for(int i=0;i<26;i++) key.append("#"+to_string(arr[i]));
            map[key].push_back(strs[i]);
        }

        for(auto x : map) ans.push_back(x.second);
        return ans;
    }
};
