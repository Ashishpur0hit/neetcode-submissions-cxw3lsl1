class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(),col = matrix[0].size(),i = 0,j = 0;
        while(i!=row-1 && matrix[i+1][j]<=target)
        {
            if(matrix[i+1][j]==target) return true;
            i++;
        }
        while(j<col)
        {
            if(matrix[i][j]==target) return true;
            else j++;
        }
        return false;
    }
};
