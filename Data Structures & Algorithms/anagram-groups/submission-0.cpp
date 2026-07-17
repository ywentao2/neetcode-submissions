class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> out;
        map<vector<int>, vector<string>> m;
        for (string s : strs) {
            vector<int> freq(26, 0);
            for (int i = 0; i < s.length(); ++i) {
                freq[s[i] - 'a']++;
            }
            auto it = m.find(freq);
            if (it == m.end()) {
                vector<string> l;
                l.push_back(s);
                m.insert({freq, l});
            }
            else {
                it->second.push_back(s);
            }
        }
        for (auto iter = m.begin(); iter != m.end(); iter++) {
            out.push_back(iter->second);
        }
        return out;
    }
};
