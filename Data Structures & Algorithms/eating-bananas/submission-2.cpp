class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto max = max_element(piles.begin(), piles.end());
        if (h == piles.size()) return *max;
        int l = 1, r = *max;
        while (l < r) {
            int hrs = 0;
            int mid = l+(r-l)/2;
            for (int i : piles) {
                hrs += ((i + mid - 1) / mid);
            }
            if (hrs <= h) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }
};
