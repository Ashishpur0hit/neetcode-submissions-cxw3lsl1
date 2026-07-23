class Solution {
public:
    int n1, n2, n3;
    bool fun(string &s1,string &s2,string &s3,int i,int j,vector<vector<int>>&dp)
    {
        if(i==n1 && j==n2) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        int k=i+j;
        bool ans = false;
        if(i<n1 && s1[i]==s3[k]) ans|=fun(s1,s2,s3,i+1,j,dp);
        if(j<n2 && s2[j]==s3[k]) ans |=fun(s1,s2,s3,i,j+1,dp);
        dp[i][j]= ans;
        return dp[i][j];
    }
    bool isInterleave(string s1, string s2, string s3) {
        n1=s1.length(),n2=s2.length(),n3=s3.length();
        if(n1+n2!=n3) return false;
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        return fun(s1,s2,s3,0,0,dp);
    }
};
