class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        std::string res;
        res.reserve(s.size());

        const int cycle = (numRows << 1) - 2;

        for (int i = 0; i < numRows; ++i) {
            int step = cycle - 2 * i;
            if (!step) step = cycle;
            for (int j = i; j < s.size();
                j += step, step = cycle - (step % cycle)) {
                res += s[j];
            }
        }

        return res;
    }
};