class Solution {
public:
    int climbStairs(int n) {
        int step1 = 1, step2 = 2;
        if (n <= 2) return n;
        for (int i = 2; i < n; ++i) {
            int tmp = step2;
            step2 += step1;
            step1 = tmp;
        }
        return step2;
    }
};
