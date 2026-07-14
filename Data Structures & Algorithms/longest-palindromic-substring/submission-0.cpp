class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(),max_len=1;
        string ans="";
        ans.push_back(s[0]);

        for(int i=0;i<n;i++)
        {
            int left=i-1,right=i+1;
            while(left>=0 && right <n)
            {
                if(s[left]==s[right]) left--,right++;
                else break;
            }
            if(right-left-1>max_len) max_len=right-left-1,ans=s.substr(left+1,max_len);
        }   


        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                int left=i-1,right=i+2;
                while(left>=0 && right<n)
                {
                    if(s[left]==s[right]) left--,right++;
                    else break;
                }
                if(right-left-1>max_len) max_len = right-left-1,ans = s.substr(left+1,max_len);
            }
        } 
        return ans;
    }
};
