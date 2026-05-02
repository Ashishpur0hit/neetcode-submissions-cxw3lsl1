class Solution {
public:
    string minWindow(string s, string t) {
        int n1=s.length(),count=t.length(),left=0,min_len = INT_MAX;
        string ans="";
        unordered_map<char,int>map;
        for(auto x : t) map[x]++;

        for(int right=0;right<n1;right++)
        {
            if(map[s[right]]>0) count--;
            map[s[right]]--;

            while(count==0)
            {
                if(min_len>(int)s.substr(left,right-left+1).length()) min_len = s.substr(left,right-left+1).length(),ans = s.substr(left,right-left+1);

                map[s[left]]++;
                if(map[s[left]]>0) count++;
                left++;
            }
        }
        return ans;
    }
};
