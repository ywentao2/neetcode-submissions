class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int islands = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                char c = grid[i][j];
                if (c == '1') {
                    ++islands;
                    dfs(i, j, grid);
                } 
            }
        }
        return islands;
    }
    void dfs(int row, int col, vector<vector<char>>& grid) {
        if (col < 0 || col >= cols || row < 0 || row >= rows || grid[row][col] == '0') return;
        else {
            grid[row][col] = '0';
            dfs(row, col+1, grid);
            dfs(row, col-1, grid);
            dfs(row+1, col, grid);
            dfs(row-1, col, grid);
        }
    }
private:
    int cols;
    int rows;
};
