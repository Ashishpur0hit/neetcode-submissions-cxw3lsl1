class Solution {
public:
    int rows,cols;
    vector<pair<int,int>>directions={{1,0},{0,1},{-1,0},{0,-1}};
    int fun(vector<vector<int>>&matrix,vector<vector<int>>&dp,int i,int j)
    {
        if(dp[i][j]!=-1) return dp[i][j];
        int path=1;
        for(auto x : directions)
        {
            
            int new_i = i+x.first,new_j = j+x.second;
            if(new_i>=0 && new_i<rows &&
             new_j>=0 && new_j<cols &&
              matrix[new_i][new_j]>matrix[i][j])
            {
                path = max(path,1+fun(matrix,dp,new_i,new_j));
            }
        }

        dp[i][j]=path;
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        rows=matrix.size(),cols=matrix[0].size();
        vector<vector<int>>dp(rows,vector<int>(cols,-1));
        int max_path=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                max_path = max(max_path,fun(matrix,dp,i,j));
            }
        }
        return max_path;
    }
};
