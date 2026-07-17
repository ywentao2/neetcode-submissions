class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> weight;
        for (int i : stones) weight.push(i);
        while (weight.size() > 1) {
            int x = weight.top();
            weight.pop();
            int y = weight.top();
            weight.pop();
            if (x == y) continue;
            if (y < x) weight.push(x - y);
        }
        if (weight.size() == 0) weight.push(0);
        return weight.top();
    }
};
