class Solution {
public:
    int n1,n2;
    int fun(string & word1 , string & word2 ,int i ,int j,vector<vector<int>>&dp)
    {
        if(i>=n1) return n2-j;
        if(j>=n2) return n1-i;
        if(dp[i][j]!=-1) return dp[i][j];

        if(word1[i]==word2[j]) dp[i][j] = fun(word1,word2,i+1,j+1,dp);
        else
        {
            int insert = fun(word1,word2,i,j+1,dp);
            int remove = fun(word1,word2,i+1,j,dp);
            int replace = fun(word1,word2,i+1,j+1,dp);

            dp[i][j] = 1+min(insert,min(remove,replace));
        }
        return dp[i][j];
    }
    int minDistance(string word1, string word2) {
        n1=word1.length(),n2=word2.length();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return fun(word1,word2,0,0,dp);
    }
};
