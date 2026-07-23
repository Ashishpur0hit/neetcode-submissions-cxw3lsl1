class Solution {
public:
    bool fun(string &s1,string &s2,string &s3,int i,int j,int k,int n1,int n2,int n3,vector<vector<vector<int>>>&dp)
    {
        if(k==n3) return true;
        if(i<n1 && j<n2 && dp[i][j][k]!=-1) return dp[i][j][k];
        int opt1,opt2;
        if(i<n1 && j<n2)
        {
            if(s1[i] == s3[k] && s2[j]==s3[k])
            {
                opt1 = fun(s1,s2,s3,i+1,j,k+1,n1,n2,n3,dp);
                opt2 = fun(s1,s2,s3,i,j+1,k+1,n1,n2,n3,dp);
            }
            else if(s1[i]==s3[k])
            {
                // incr i;
                opt1 = fun(s1,s2,s3,i+1,j,k+1,n1,n2,n3,dp);
                opt2 = false;
            }
            else if(s2[j]==s3[k])
            {
                //incr j;
                opt1 = false;
                opt2 = fun(s1,s2,s3,i,j+1,k+1,n1,n2,n3,dp);
            }
            else 
            {
                opt1 = false;
                opt2 = false;
            }
        }
        else if(i<n1)
        {
            //incr i;
            if(s3.substr(k)==s1.substr(i)) return true;
            return false;
        }
        else 
        {
            //incr j;
           if(s3.substr(k)==s2.substr(j)) return true;
           return false;
        }


        dp[i][j][k] = opt1 || opt2;
        return dp[i][j][k];
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length(),n2 = s2.length(),n3=s3.length();
        if(n1+n2!=n3) return false;
        vector<vector<vector<int>>>dp(n1,vector<vector<int>>(n2,vector<int>(n3,-1)));
        return fun(s1,s2,s3,0,0,0,n1,n2,n3,dp);
    }
};
