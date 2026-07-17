class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (!m) return false;
        int l = 0, r = m * n - 1;
            while (l <= r) {
            int m = l+(r-l)/2;
            int i = m / n;
            int j = m % n;
            if (matrix[i][j] < target) {
                l = m+1;
            }
            else if (matrix[i][j] > target) {
                r = m-1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};
