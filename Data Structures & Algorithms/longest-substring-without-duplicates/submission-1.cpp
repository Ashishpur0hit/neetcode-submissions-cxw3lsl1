class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length() , left = 0 , right = 0 , max_len = 0;
        unordered_map<char,int>map;
        while(right<n)
        {
            map[s[right]]++;
            if(map[s[right]]!=1)
            {
                max_len = max(max_len,right-left);
                while(map[s[right]]!=1)
                {
                    map[s[left]]--;
                    left++;
                }
            }
            right++;
        }

        max_len = max(max_len,right-left);

        return max_len;
    }
};
