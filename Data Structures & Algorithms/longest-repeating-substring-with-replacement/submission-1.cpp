class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length(),left=0,curr_len=0,max_len=0,max_freq=0;
        unordered_map<char,int>map;
        for(int right=0;right<n;right++)
        {
            map[s[right]]++;
            max_freq = max(max_freq,map[s[right]]);
            curr_len = right-left+1;
            while(curr_len - max_freq > k) map[s[left]]--,left++,curr_len = right-left+1;

            max_len = max(max_len,curr_len);
        }
        return max_len;
    }
};
