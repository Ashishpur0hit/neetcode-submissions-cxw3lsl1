class Solution {
public:

    vector<string>strs={};
    string encode(vector<string>& strs) {
        string ans = "";
        this->strs=strs;
        for(auto x : strs) ans+=x+" ";
        return ans;
    }

    vector<string> decode(string s) {
        return strs;
    }
};
