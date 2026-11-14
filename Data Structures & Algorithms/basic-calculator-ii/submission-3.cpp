class Solution {
public:
    int calculate(string s) {
        std::vector<int> data;
        std::vector<char> ops;

        for (int i = 0; i < s.size(); ++i) {
            const char c = s[i];

            if (c == ' ') continue;

            if (std::isdigit(c)) {
                data.push_back(num(s, i));
                while (!ops.empty() &&
                    (ops.back() == '/' || ops.back() == '*'))
                {
                    const int b = data.back(); data.pop_back();
                    if (ops.back() == '/') {
                        data.back() /= b;
                    } else {
                        data.back() *= b;
                    }
                    ops.pop_back();
                }
                continue;
            }
            
            ops.push_back(c);
        }

        int res = data.front();
        for (int i = 1; i < data.size(); ++i) {
            if (ops[i - 1] == '+') res += data[i];
            else res -= data[i];
        }

        return res;
    }

private:
    int num(const std::string& s, int& i) {
        int res = 0;
        while (s[i] == ' ') ++i;
        while (i < s.size() && std::isdigit(s[i])) {
            res *= 10;
            res += (s[i] - '0');
            ++i;
        }
        --i;
        return res;
    }
};