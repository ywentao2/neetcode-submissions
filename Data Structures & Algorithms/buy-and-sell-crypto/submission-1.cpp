class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1, best = 0, curr = 0;
        while (r < prices.size()) {
            curr = prices[r] - prices[l];
            if (curr > best) best = curr;
            if (prices[r] < prices[l]) {
                l = r;
                r++;
            }
            else {
                r++;
            }
        }
        return best;
    }
};
