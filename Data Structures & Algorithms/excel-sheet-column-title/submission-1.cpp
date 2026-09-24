class Solution {
public:
    string convertToTitle(int n) {
        std::string res;

        while (n) {
            res += static_cast<char>((n - 1) % 26) + 'A';
            n = (n - 1)/26;
        }

        std::ranges::reverse(res);
        return res;
    }
};