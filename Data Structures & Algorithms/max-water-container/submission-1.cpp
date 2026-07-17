class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_area = 0;
        int curr = 0;
        int l = 0, r = heights.size() - 1;
        while (l < r) {
            curr = min(heights[l], heights[r]) * (r - l);
            max_area = max(curr, max_area);
            if (heights[l] > heights[r]) --r;
            else ++l;
        }
        return max_area;
    }
};
