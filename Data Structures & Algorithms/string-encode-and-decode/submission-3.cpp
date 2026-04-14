class Solution {
public:
    vector<int>v;
    string encode(vector<string>& strs) {
        string encoded = "";
        for(auto x : strs)
        {
            v.push_back(x.length());
            encoded+=x;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        for(auto x : v)
        {
            ans.push_back(s.substr(0,x));
            s=s.substr(x);
        }
        return ans;
    }
};
