/*
here we cannot flatten the linked list but we can use some other approach
Approach - start from the top right of the matrix and then move down based on the conditions.
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int i = 0, j = cols-1;
        while(i < rows && cols >= 0){
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j] < target) i++;
            else j--;
        }
        return false;
    }
};