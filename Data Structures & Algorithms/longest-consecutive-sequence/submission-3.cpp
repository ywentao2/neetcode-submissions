class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        map<int, int> m;
        int count = 1;
        int max_count = 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(nums[i]) == m.end()) {
                m.insert({nums[i], 1});
            }
        }
        for (auto& pair : m) {
            if ((m.find(pair.first - 1) != m.end())) {
                count++;
                max_count = max(max_count, count);
                cout << "yay " << pair.first << endl;
            }
            else {
                cout << "huh " << pair.first << endl;
                count = 1;
            }
        }
        return max_count;
    }
};
