class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size() , col = matrix[0].size() ,  n = row*col , start = 0 , end = n-1;
        while(start<=end)
        {
            int mid = (end-start)/2+start;
            if(matrix[mid/col][mid%col]==target) return true;
            else if(matrix[mid/col][mid%col]>target) end=mid-1;
            else start=mid+1;
        }
        return false;
    }
};
