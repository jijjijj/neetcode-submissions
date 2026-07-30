class Solution {
public:
    string multiply(string num1, string num2) {
        const int len1 = num1.size();
        const int len2 = num2.size();

        std::ranges::reverse(num1);
        std::ranges::reverse(num2);

        std::string res(len1 + len2, '\0');

        for (int i = 0; i < len1; ++i) {
            int carry = 0;
            for (int j = 0; j < len2; ++j) {
                const int n2 = num2[j] - '0';
                const int n1 = num1[i] - '0';

                char& cell = res[i + j];
                int dig = n1 * n2 + carry + cell;

                cell = dig % 10;
                carry = dig / 10;
            }
            res[len2 + i] = carry;
        }

        int i = res.size() - 1;
        for (; i >= 0; --i) {
            if (res[i]) break;
        }

        res.resize(std::max(i + 1, 1));

        for (char& c : res) c += '0';
        std::ranges::reverse(res);

        return res;
    }
};
