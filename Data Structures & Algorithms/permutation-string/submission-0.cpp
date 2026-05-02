class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.length(),n2=s2.length(),index=0;
        unordered_map<char,int>map1,map2;
        for(auto x : s1) map1[x]++;
        while(index<=n2-n1)
        {
            string sub = s2.substr(index,n1);
            for(auto x : sub) map2[x]++;
            if(map1==map2) return true;
            map2.clear();
            index++;
        }
        return false;
    }
};
