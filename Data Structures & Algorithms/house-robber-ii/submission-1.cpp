class Solution {
public:
    array<int, 101> memo = {};
    int dfs(int i, int end, vector<int>& nums) {
        if (i >= end) return 0;
        if (memo[i] == 0) memo[i] = max(nums[i] + dfs(i+2, end, nums), dfs(i+1, end, nums));
        return memo[i];
    }

    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int a = dfs(0, nums.size()-1, nums);
        memo.fill(0);
        int b = dfs(1, nums.size(), nums);
        return max(a, b);
    }
};
