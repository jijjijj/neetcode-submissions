class Solution {
public:
    string convert(string s, int numRows) {
        if (s.size() == 1) return s;
              
        std::vector<std::string> parts(numRows);
        int dir = 1;
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