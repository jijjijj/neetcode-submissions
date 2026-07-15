class Solution {
public:
    bool checkValidString(string s) {
        int balance = 0;
        int asterisks = 0;

        for (char c : s) {
            if (c == '(')
                ++balance;
            else if (c == ')')
                --balance;
            else
                ++asterisks;
        }

        return std::abs(balance) <= asterisks;
    }
};
