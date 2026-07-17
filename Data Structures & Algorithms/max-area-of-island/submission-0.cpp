class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int curr = 0;
        rows = grid.size();
        cols = grid[0].size();
        if (grid.size() == 0) return 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    curr = dfs(i, j, grid);
                    maxArea = max(maxArea, curr);
                }
            }
        }
        return maxArea;
    }
    int dfs(int row, int col, vector<vector<int>>& grid) {
        if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] == 0) return 0;
        else {
            grid[row][col] = 0;
            return 1 + dfs(row+1, col, grid) + dfs(row-1, col, grid) + dfs(row, col+1, grid) + dfs(row, col-1, grid);
        } 
    }

private: 
    int rows;
    int cols;
};
