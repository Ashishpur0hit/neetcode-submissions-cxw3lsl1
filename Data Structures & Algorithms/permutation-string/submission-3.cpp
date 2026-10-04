class Solution {
public:
    bool isAnagram(string str1,string str2)
    {
        vector<int>v(26,0);
        for(auto x : str1) v[x-'a']++;
        for(auto x : str2) v[x-'a']--;
        for(auto x : v) if(x!=0) return false;
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int n = s2.length(),m=s1.length();
        for(int i=0;i<=n-m;i++)
        {
            if(isAnagram(s1,s2.substr(i,m))) return true;
        }
        return false;
    }
};
