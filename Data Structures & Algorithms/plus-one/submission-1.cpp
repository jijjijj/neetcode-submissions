#include <ranges>

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        std::ranges::reverse(digits);

        int carry = 1;

        for (int& i : digits) {
            i += carry;
            if (i < 10) {
                carry = 0;
                break;
            }
            i %= 10;
        }

        if (carry) digits.emplace_back(1);

        std::ranges::reverse(digits);

        return digits;
    }
};
