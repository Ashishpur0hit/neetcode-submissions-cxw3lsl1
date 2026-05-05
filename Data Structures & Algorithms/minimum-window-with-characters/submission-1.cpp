class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length(),count=t.length(), left=0,len = INT_MAX;
        string ans="";
        unordered_map<char,int>freq1;
        for(auto x : t) freq1[x]++;

        for(int right=0;right<n;right++)
        {
            if(freq1[s[right]]>0) count--;
            freq1[s[right]]--;


            while(count==0)
            {
                if(right-left+1<len) len = right-left+1,ans = s.substr(left,right-left+1);

                freq1[s[left]]++;
                if(freq1[s[left]]>0) count++;
                left++;
            }
        }
        return ans;
    }
};
