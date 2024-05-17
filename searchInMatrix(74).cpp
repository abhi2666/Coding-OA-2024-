/*
matrix is already sorted so you just have to apply binary search and and convert the 2D index to 1D index..
*/

// this code will not work for this type of question
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int low = 0, high = rows*cols-1;
        while(low <= high){
            int mid = (low + high)/2;
            int i = mid/cols;
            int j = mid%cols;
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j] < target) high = mid - 1;
            else low = mid + 1;
        }
        return false;
    }
};