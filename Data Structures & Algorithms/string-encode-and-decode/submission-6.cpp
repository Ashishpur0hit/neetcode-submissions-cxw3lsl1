class Solution {
public:
    vector<int>v;
    string encode(vector<string>& strs) {
        string str = "";
        for(auto x : strs)
        {
            str.append(x);
            v.push_back(x.length());
        }
        return str;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        for(auto x : v)
        {
            strs.push_back(s.substr(0,x));
            s=s.substr(x);
        }
        return strs;
    }
};
