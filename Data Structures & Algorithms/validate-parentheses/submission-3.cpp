class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) return false;
        vector<char> open;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                open.push_back(s[i]);
            }
            else {
                if (open.size() == 0) return false;
                char c = open[open.size()-1];
                if (s[i] == ')') {
                    if (c != '(') return false;
                }
                else if (s[i] == ']') {
                    if (c != '[') return false;
                }
                else {
                    if (c != '{') return false;
                }
                open.pop_back();
            }
        }
        if (open.size() > 0) return false;
        return true;
    }
};
