class Solution {
public:
    string intToRoman(int num) {
        std::string res;
        int power = 1000;

        std::unordered_map<int,
            std::unordered_map<int, char>> mp{
            { 1, {
                { 1, 'I' },
                { 5, 'V' },
                { 10, 'X' },
            }},
            { 10, {
                { 1, 'X' },
                { 5, 'L' },
                { 10, 'C' },
            }},
            { 100, {
                { 1, 'C' },
                { 5, 'D' },
                { 10, 'M' },
            }},
            { 1000, {
                { 1, 'M' },
            }},
        };

        /*
        9 - IX XC
        8 - VIII LXXX
        7 - VII
        6 - VI
        5 - V
        4 - IV
        3 - III
        2 - II
        1 - I
        */

        while (num) {
            const int digit = (num / power);

            if (digit) {
                if (digit == 9) {
                    res += mp[power][1];
                    res += mp[power][10];
                } else if (digit >= 5 && digit <= 8) {
                    res += mp[power][5];
                    for (int i = 0; i < digit - 5; ++i) {
                        res += mp[power][1];
                    }
                } else if (digit == 4) {
                    res += mp[power][1];
                    res += mp[power][5];
                } else {
                    for (int i = 0; i < digit; ++i) {
                        res += mp[power][1];
                    }
                }
            }


            num %= power;
            power /= 10;
        }
        return res;
    }
};