class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> m;
        int longest = 0, curr = 0;
        int l = 0, r = 0;
        while (l <= r && r < s.size()) {
            cout << s[r] << endl;
            if (m.find(s[r]) == m.end()) {
                m.insert({s[r], 1});
                curr++;
                cout << curr << endl;
                r++;
            }
            else if (m.at(s[r])) {
                m.clear();
                cout << "erase " << s[r] << " at " << curr << endl; 
                curr = 0;
                cout << "new curr: " << curr << endl;
                l++;
                r = l;
            }
            longest = max(curr, longest);
        }
        return longest;
    }
};
