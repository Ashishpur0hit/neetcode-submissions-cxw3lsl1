class Solution {
public:
    bool isAnagram(string s, string t) {
        int s_len = s.length(),t_len = t.length();
        if(s_len != t_len) return false;
        vector<int>v(26,0);
        for(int i=0;i<s_len;i++) v[s[i]-'a']++,v[t[i]-'a']--;
        for(int i=0;i<26;i++) if(v[i]!=0) return false;
        return true;
        
    }
};
