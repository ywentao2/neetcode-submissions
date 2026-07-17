class Solution {
public:
    // void helper(string tmp) {
    //     stack<char> sub;
    //     stack<int> numbers;
        
    //     // for (int i = 0; i < tmp.size(); ++i) {
    //     //     if (isdigit(tmp[i])) {
    //     //         numbers.push(tmp[i] - '0');
    //     //     }
    //     //     else if (tmp[i] == ']') {
    //     //         string tmp2 = "";
    //     //         while(sub.top() != '[') {
    //     //             tmp2 += sub.top();
    //     //             cout << "popped " << sub.top() << endl;
    //     //             sub.pop();
    //     //         }
    //     //         cout << numbers.top() << endl;
    //     //         for (int i = 0; i < numbers.top(); ++i) {
    //     //             ans += tmp2;
    //     //             cout << i << "th time" << endl;
    //     //         }
    //     //         numbers.pop();
    //     //     }
    //     //     else {
    //     //         sub.push(tmp[i]);
    //     //     }
    //     // }
    // }
    string decodeString(string s) {
        //similar to parenthesis thing?
        //when you see [, save curr number and string
        //when you see ], repeat n times and attach to ans
        stack<int> numbers;
        stack<string> prev;
        string curr = "";
        int num = 0;
        for (char c : s) {
            if (isdigit(c)) num = num * 10 + (c - '0'); //converting multidigit char one at a time to int
            else if (c == '[') {
                numbers.push(num);
                prev.push(curr);
                num = 0;
                curr = "";
            }
            else if (c == ']') {
                int repeat = numbers.top();
                numbers.pop();
                string prevString = prev.top();
                prev.pop();
                string repeated = "";
                for (int i = 0; i < repeat; ++i) repeated += curr;
                curr = prevString + repeated;
            }
            else {
                curr += c;
            }
        }
        return curr;
    }
};