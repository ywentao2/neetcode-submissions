class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int, int> box;
        map<int, int> row;
        map<int, int> col;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') continue;
                int d = c - '0';
                if (row.count(d) == 0) row.insert({d, 1});
                else return false;
            }
            row.clear();
        } 
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[j][i];
                if (c == '.') continue;
                int d = c - '0';
                if (col.count(d) == 0) col.insert({d, 1});
                else return false;
            }
            col.clear();
        }

        vector<vector<int>> starts = {{0,0}, {0,3}, {0,6}, {3,0}, {3,3}, {3,6}, {6,0}, {6,3}, {6,6}};

        for (int s = 0; s < 9; ++s) {
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    char c = board[starts[s][0] + i][starts[s][1] + j];
                    if (c == '.') continue;
                    int d = c - '0';
                    if (box.count(d) == 0) box.insert({d, 1});
                    else return false;
                }
            }
            box.clear();
        }
        return true;
    }
};
