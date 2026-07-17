class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> num;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                num.push_back(stoi(tokens[i]));
            }
            else {
                int b = num.back();
                num.pop_back();
                int a = num.back();
                num.pop_back();
                int r = 0;
                if (tokens[i] == "+") r = a + b;
                else if (tokens[i] == "-") r = a - b;
                else if (tokens[i] == "*") r = a * b;
                else r = a / b;
                num.push_back(r);
            }
        }
        return num[0];
    }
};
