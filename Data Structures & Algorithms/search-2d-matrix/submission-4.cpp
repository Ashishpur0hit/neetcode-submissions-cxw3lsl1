class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top=0,bottom=matrix.size()-1,row;
        while(top<=bottom)
        {
            row=(top+bottom)/2;
            if(matrix[row][0]<target and matrix[row][matrix[row].size()-1]>target) break;
            else if(matrix[row][0]>target) bottom=row-1;
            else top=row+1;
        }
        row=(top+bottom)/2;
        cout<<"row = "<<row<<endl;

        int start=0,end=matrix[0].size()-1;
        while(start<=end)
        {
            int col=(start+end)/2;
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col]<target) start=col+1;
            else end=col-1;
        }
        return false;
    }
};
