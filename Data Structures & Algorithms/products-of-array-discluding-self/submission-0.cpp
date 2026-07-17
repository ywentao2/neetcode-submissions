class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> out(size, 1);
        int pre = 1, suf = 1;
        for (int i = 0; i < size; ++i) {
            out[i] = pre;
            pre *= nums[i];
        }
        for (int i = size-1; i >= 0; --i) {
            out[i] *= suf;
            suf *= nums[i];
        }
        return out;
    }
};
