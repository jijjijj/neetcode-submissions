class Solution {
public:
    string convert(string s, int numRows) {       
        std::string res;
        res.reserve(s.size());

        for (int i = 0; i < numRows; ++i) {
            int step = std::max(1, 2 * (numRows - 1));

            for (int j = i; j < s.size(); j += step) {
                res += s[j];

                if (i > 0 && i < numRows - 1 &&
                    j + step - 2 * i < s.size()) {
                    res += s[j + step - 2 * i];
                }
            }
        }

        return res;
    }
};