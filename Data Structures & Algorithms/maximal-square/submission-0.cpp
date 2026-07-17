class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        //dp, instead of tracking the actual area, we track the side length ending at i,j as well as the max length seen so far
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0)); //dont forget to preallocate
        //we have to do like this bc matrix is a char vector, not an int vector
        int maxSide = 0;
        for (int i = 0; i < cols; ++i) {
            dp[0][i] = matrix[0][i] - '0';
            maxSide = max(maxSide, dp[0][i]);
        }
        for (int i = 0; i < rows; ++i) {
            dp[i][0] = matrix[i][0] - '0';
            maxSide = max(maxSide, dp[i][0]);
        }
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                // if (dp[i-1][j] > 0 && dp[i][j-1] > 0 && dp[i-1][j-1] > 0) {
                    //wrong
                // }
                if (matrix[i][j] == '1') {
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}); //check up, left, and diag before
                }
                maxSide = max(maxSide, dp[i][j]);
            }
        }
        // return dp[rows-1][cols-1];
        return pow(maxSide, 2);
    }
};