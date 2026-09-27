class Solution {
public:
    string convert(string s, int numRows) {       
        std::string res;
        res.reserve(s.size());

        const int cycle = std::max(1, (numRows << 1) - 2);

        for (int i = 0; i < numRows; ++i) {
            int step = 2 * i;

            for (int j = i; j < s.size(); j += step) {
                res += s[j];
                step = cycle - (step % cycle);
            }
        }

        return res;
    }
};