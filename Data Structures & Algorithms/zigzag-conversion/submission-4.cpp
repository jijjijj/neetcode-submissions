class Solution {
public:
    string convert(string s, int numRows) {
        std::vector<std::string> parts(numRows);
        int dir = std::min(numRows - 1, 1);
        int row = 0;

        for (const char c : s) {
            parts[row] += c;
            row += dir;

            if (row == 0 || row == numRows - 1)
                dir *= -1;
        }

        std::string res;
        res.reserve(s.size());

        for (const auto& part : parts) {
            res += part;
        }

        return res;
    }
};