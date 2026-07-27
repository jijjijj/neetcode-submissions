#include <ranges>

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;

        for (int& i : digits | std::views::reverse) {
            i += carry;
            if (i < 10) {
                carry = 0;
            }
            i %= 10;
        }

        if (carry) digits.insert(digits.begin(), 1);

        return digits;
    }
};
