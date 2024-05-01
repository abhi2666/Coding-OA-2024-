class Solution {
private:
    int currArea;
    void dfs(int i, int j, int rows, int cols, vector<vector<int>>&grid, vector<vector<int>>&vis){
        vis[i][j] = 1;
        int dir_r [] = {0, -1, 0, 1};
        int dir_c [] = {-1, 0, 1, 0};
        // check all four cardinal directions
        for(int k = 0; k < 4; k++){
            int new_r = dir_r[k] + i;
            int new_c = dir_c[k] + j;
            if(new_r >= 0 && new_r < rows && new_c >= 0 && new_c < cols && grid[new_r][new_c]==1 && vis[new_r][new_c]==0){
                //found a valid 1
                currArea++;
                dfs(new_r, new_c, rows, cols, grid, vis);
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // find the island with max area..can be done with BFS
        int mxArea = 0;
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>>vis(rows, vector<int>(cols, 0));
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j]==1 && !vis[i][j]) {
                    currArea = 1;
                    dfs(i, j, rows, cols, grid, vis);
                    mxArea = max(mxArea, currArea);
                }
            }
        }
        return mxArea;
    }
};