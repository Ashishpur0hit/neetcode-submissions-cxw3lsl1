class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n==0) return 0;
        int left=0,right=0,max_len=0;
        unordered_map<char,int>map;
        while(right<n)
        {
            while(map[s[right]]>0)
            {
                map[s[left]]--;
                left++;
            }
            map[s[right]]++;
            max_len=max(max_len,right-left+1);
            right++;
        }
        return max_len;
    }
};
