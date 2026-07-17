class StockSpanner {
public:
    StockSpanner() {
    }
    
    int next(int price) {
        int sol = 0;
        prices.push_back(price);
        int n = prices.size();
        for (int i = n-1; i >= 0; --i) {
            if (prices[i] <= price) sol++;
            else break;
        }
        return sol;

    }
    vector<int> prices;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */