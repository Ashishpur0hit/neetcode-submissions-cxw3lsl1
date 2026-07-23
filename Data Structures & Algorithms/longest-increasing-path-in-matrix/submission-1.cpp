class Solution {
public:
    int rows,cols;
    vector<pair<int,int>>directions={{1,0},{-1,0},{0,1},{0,-1}};
    int fun(vector<vector<int>>& matrix,int i,int j,vector<vector<int>>&dp)
    {
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=1;
        for(auto x : directions)
        {
            int a = i+x.first,b=j+x.second;
            if(a>=0 && a<rows && b>=0 && b<cols && matrix[a][b]>matrix[i][j]) 
            {
                ans = max(ans,1+fun(matrix,a,b,dp));
            }
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        rows = matrix.size(),cols = matrix[0].size();
        vector<vector<int>>dp(rows,vector<int>(cols,-1));
        int ans = 0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                int tmp = fun(matrix,i,j,dp);
                cout<<tmp<<endl;
                ans = max(ans,tmp);
            }
        }
        return ans;
    }
};
