class Solution {
public:
    string convertToTitle(int n) {
        std::string res;

        while (n) {
            --n;
            res += static_cast<char>(n % 26) + 'A';
            n /= 26;
        }

        std::ranges::reverse(res);
        return res;
    }
};