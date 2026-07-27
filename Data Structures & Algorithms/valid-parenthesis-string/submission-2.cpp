class Solution {
public:
    bool fun(string &s,int i,int open,vector<vector<int>>&dp)
    {
        if(i>=s.size())
        {
            if(open!=0) return false;
            return true;
        }
        if(open==0 && s[i]==')') return false;
        if(dp[i][open]!=-1) return dp[i][open];

        if(s[i]=='(')
        {
            dp[i][open]= fun(s,i+1,open+1,dp);
            return dp[i][open];
        }
        else if(s[i]==')')
        {
            dp[i][open]= fun(s,i+1,open-1,dp);
            return dp[i][open];
        }
        
            // empty string
            bool opt1 = fun(s,i+1,open,dp);
            bool opt2 = fun(s,i+1,open+1,dp);
            bool opt3 =false;
            if(open>0) opt3= fun(s,i+1,open-1,dp);
            dp[i][open]= opt1 || opt2 || opt3;
            return dp[i][open];
        
    }
    bool checkValidString(string s) {
        int n = s.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return fun(s,0,0,dp);
    }
};
