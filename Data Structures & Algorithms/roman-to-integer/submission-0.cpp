class Solution {
public:
    int romanToInt(string s) {
        int biggest = 0;
        int res = 0;

        std::unordered_map<char, int> mp = {
            { 'I', 1 }, { 'V', 5 },
            { 'X', 10 }, { 'L', 50 },
            { 'C', 100 }, { 'D', 500 },
            { 'M', 1000 }
        };

        for (int i = s.size() - 1; i >= 0; --i) {
            const int val = mp[s[i]];

            res += (val >= biggest ? val : -val);
            biggest = std::max(biggest, val);
        }

        return res;
    }
};