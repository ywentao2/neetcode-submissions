class Solution {
public:
    array<int, 101> steps = {};
    int dfs(int i, vector<int>& cost) {
        if (i >= cost.size()) return 0;
        if (steps[i] == 0) steps[i] = cost[i] + min(dfs(i+1, cost), dfs(i+2, cost));
        return steps[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        return min(dfs(0, cost), dfs(1, cost));
    }
};
