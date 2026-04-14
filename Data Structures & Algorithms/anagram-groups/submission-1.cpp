class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>map;
        for(auto x : strs)
        {
            int arr[26]={0};
            string key="";
            for(int i=0;i<x.length();i++)    arr[x[i]-'a']++;
            for(int i=0;i<26;i++) key+="#"+to_string(arr[i]);
            map[key].push_back(x);
        }
        vector<vector<string>>result;
        for(auto pair : map)
        {
            result.push_back(pair.second);
        }
        return result;
    }
};
