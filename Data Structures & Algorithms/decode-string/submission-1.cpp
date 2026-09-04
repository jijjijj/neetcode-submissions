class Solution {
public:
    // recursive
    // one stack
    // two stacks
    string decodeString(string str) {
        int i = 0;
        return decode(str, i);
    }

private:
    std::string decode(const std::string& str, int& i) {
        std::string cur;
        int k = 0;

        for (; i < str.size(); ++i) {
            const char c = str[i];
            if (c == '[') {
                ++i;
                const std::string s = decode(str, i);
                std::stringstream ss;
                for (; k > 0; --k) ss << s;
                cur += ss.str();
            } else if (std::isdigit(c)) {
                k = (k * 10) + (c - '0');
            } else if (c == ']') {
                return cur;
            } else {
                cur += c;
            }
        }

        return cur;
    }
};