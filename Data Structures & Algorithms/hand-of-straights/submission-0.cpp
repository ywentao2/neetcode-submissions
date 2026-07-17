class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(), hand.end());
        int n = hand.size();
        unordered_map<int, int> freq;
        for (int i : hand) {
            if (freq.find(i) == freq.end()) {
                freq.insert({i, 1});
            }
            else {
                freq[i]++;
            }
        }
        for (int i = 0; i < n; ++i) {
            int start = hand[i];
            if (freq[start] == 0) continue;
            for (int j = 0; j < groupSize; ++j) {
                int tmp = hand[i] + j;
                if (freq[tmp] == 0) {
                    cout << tmp << " dne" << endl;
                    return false;
                }
                else freq[tmp]--;
            }
        }
        return true;
    }
};
