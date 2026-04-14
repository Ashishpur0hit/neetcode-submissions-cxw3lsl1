class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.size()==1) return {strs};
        unordered_map<string,vector<string>>map;
        vector<vector<string>>ans;
        for(auto x : strs)
        {
            string key="";
            int arr[26]={0};
            for(int i=0;i<x.length();i++) arr[x[i]-'a']++;
            for(int i=0;i<26;i++) key+="#"+to_string(arr[i]);
            cout<<key<<endl;
            map[key].push_back(x);
        }
        for(auto x : map) ans.push_back(x.second);
        return ans;
    }
};
