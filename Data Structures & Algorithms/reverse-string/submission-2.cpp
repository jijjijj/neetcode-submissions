class Solution {
public:
    // rec
    // stack
    void reverseString(vector<char>& str) {
        std::stack<char> s;

        for (const char c : str) s.push(c);

        int i = 0;
        while (!s.empty()) {
            str[i++] = s.top();
            s.pop();
        }
    }
};