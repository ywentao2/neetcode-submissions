class Solution {
public:
    array<int, 101> memo = {};
    int dfs(int i, vector<int>& nums) {
        if (i >= nums.size()) return 0;
        if (memo[i] == 0) memo[i] = max(nums[i] + dfs(i+2, nums), dfs(i+1, nums));
        return memo[i];
    }

    int rob(vector<int>& nums) {
        return dfs(0, nums);
    }
};
