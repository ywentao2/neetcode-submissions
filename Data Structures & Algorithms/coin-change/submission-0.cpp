class Solution {
public:
    array<int, 10001> memo = {};

    int dfs(int amt, vector<int>& coins) {
        //start with amount adn reduce down
        //instead of doing it greedily, try on every coin
        if (amt == 0) return 0;
        if (amt < 0) return INT_MAX / 2; //discourage this route
        if (memo[amt] != 0) return memo[amt];
        int best = INT_MAX/2;
        for (int i : coins) {
            best = min(best, 1 + dfs(amt - i, coins));
        }
        memo[amt] = best;
        return memo[amt];
    }
    int coinChange(vector<int>& coins, int amount) {
        int sol = dfs(amount, coins);
        if (sol >= INT_MAX/2) return -1;
        return sol;
    }
};
