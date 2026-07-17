class StockSpanner {
public:
    StockSpanner() {
    }
    
    int next(int price) {
        //naive solution
        // int sol = 0;
        // prices.push_back(price);
        // int n = prices.size();
        // for (int i = n-1; i >= 0; --i) {
        //     if (prices[i] <= price) sol++;
        //     else break;
        // }
        // return sol;

        //instead, use a stack that stores a pair of the already accumulated min and do it like that
        int span = 1;
        while (!prev.empty() && prev.top().first <= price) {
            span += prev.top().second;
            prev.pop();
        }
        prev.push({price, span});
        return span;
    }
    // vector<int> prices;
    stack<pair<int, int>> prev;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */