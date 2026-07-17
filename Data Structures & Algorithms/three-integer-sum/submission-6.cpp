class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> out;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i-1]) {
                cout << "skipping " << nums[i] << endl;
                continue;
            }
            if (nums[i] > 0) {
                cout << "bonk on " << nums[i] << endl;
            }
            int l = i+1, r = nums.size() - 1;
            while (l < r) {
                if (nums[i] + nums[r] + nums[l] < 0) {
                    cout << "left shift " << nums[i] << endl;
                    ++l;
                }
                else if (nums[i] + nums[r] + nums[l] > 0) {
                    --r;
                    cout << "right shift" << endl;
                }
                else {
                    out.push_back({nums[i], nums[r], nums[l]});
                    int L = nums[l], R = nums[r];
                    while (l < r && nums[l] == L) ++l;      
                    while (l < r && nums[r] == R) --r;
                }
            }
        }
        return out;
    }
};
