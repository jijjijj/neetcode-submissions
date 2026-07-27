class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();

        if (len1 < len2) {
            std::swap(num1, num2);
            std::swap(len1, len2);
        }

        std::string res(len1 + len2, '\0');

        for (int i = 0; i < len1; ++i) {
            int carry = 0;
            for (int j = 0; j < len2; ++j) {
                const int n2 = num2[len2 - j - 1] - '0';
                const int n1 = num1[len1 - i - 1] - '0';

                char& cell = res[res.size() - i - j - 1];
                int dig = n1 * n2 + carry + cell;

                cell = (char)(dig % 10);
                carry = dig / 10;
            }
            res[res.size() - len2 - i - 1] = (char)carry;
        }

        auto it = res.find_first_not_of('\0');
        if (it == std::string::npos) it = res.size() - 1;
        res = res.substr(it);

        for (char& c : res) c += '0';

        return res;
    }
};
