class Solution {
public:
    bool isValid(string s) {
        std::unordered_map<char, char> mp = {
            { '{', '}' },
            { '[', ']' },
            { '(', ')' }
        };

        std::stack<char> open;

        for (char c : s) {
            if (mp.contains(c)) {
                open.push(c);
            } else if (!open.empty() && mp[open.top()] == c) {
                open.pop();
            } else {
                return false;
            }
        }

        return open.empty();
    }
};
