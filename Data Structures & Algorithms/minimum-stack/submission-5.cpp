class MinStack {
public:
    MinStack() : min(INT_MAX) {}
    
    void push(int val) {
        stack.push_back(val);
        if (val <= min) {
            mins.push_back(val);
            min = val;
        }
    }
    
    void pop() {
        if (stack.size() == 1) {
            mins.clear();
            min = INT_MAX;
        }
        else if (top() == min) {
            mins.pop_back();
            min = mins[mins.size()-1];
        }
        stack.pop_back();
    }
    
    int top() {
        return stack[stack.size()-1];
    }
    
    int getMin() {
        return min;
    }
private:
    int min;
    vector<int> mins;
    vector<int> stack;
};
