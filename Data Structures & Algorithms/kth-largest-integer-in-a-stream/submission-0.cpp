class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            temp.push(nums[i]);
        }
        tk = k;
    }
    
    int add(int val) {
        temp.push(val);
        int p[tk-1];
        for (int i = 0; i < tk-1; ++i) {
            p[i] = temp.top();
            temp.pop();
        }
        int max = temp.top();
        for (int i : p) temp.push(i);
        return max;
    }
private:
    priority_queue<int> temp;
    int tk;
};
