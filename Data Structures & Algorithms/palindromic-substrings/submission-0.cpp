class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length(),ans=n;
        for(int i=0;i<n;i++)
        {
            int left=i-1,right=i+1;
            while(left>=0 && right<n)
            {
                if(s[left]==s[right]) left--,right++,ans++;
                else break;
            }
        }

        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                ans++;
                int left=i-1,right=i+2;
                while(left>=0 && right<n)
                {
                    if(s[left]==s[right]) left--,right++,ans++;
                    else break;
                }
            }
        }
        return ans;
    }
};
