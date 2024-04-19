class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        // on the go count the perimeter
        int rows = grid.size(), cols = grid[0].size();
        int perimeter = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j]==1){
                    //check all four sides
                    int dir_r[] = {0, -1, 0, 1};
                    int dir_c[] = {-1, 0, 1, 0};
                    for(int k = 0; k < 4; k++){
                        int cr = i + dir_r[k];
                        int cc = j + dir_c[k];
                        if(cr >= 0 && cr < rows && cc >= 0 && cc < cols && grid[cr][cc] != 1) perimeter++;
                        else if(cr < 0 || cr >= rows || cc < 0 || cc >= cols) perimeter++;
                    }
                }  
            }
        }
        return perimeter;
    }
};