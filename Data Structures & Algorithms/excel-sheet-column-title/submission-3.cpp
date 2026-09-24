class Solution {
public:
    string convertToTitle(int n) {
        if (!n) return "";

        --n;

        return convertToTitle(n / 26) + static_cast<char>('A' + (n % 26));
    }
};