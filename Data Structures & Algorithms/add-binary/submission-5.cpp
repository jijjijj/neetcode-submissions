class Solution {
public:
    string addBinary(string a, string b) {
        const int mx = std::max(a.size(), b.size());

        std::string res;
        res.resize(mx);

        int i = a.size() - 1;
        int j = b.size() - 1;
        int at = 0;

        bool carry = 0;
        while (i >= 0 || j >= 0) {
            const bool v1 = i >= 0 ? a[i] - '0' : 0;
            const bool v2 = j >= 0 ? b[j] - '0' : 0;

            res[at++] = (carry ^ v1 ^ v2) + '0';
            carry = (v1 && v2) || (v1 && carry) || (v2 && carry);

            --j;
            --i;
        }

        // 10010
        //   111
        if (carry) res += '1';
        
        std::ranges::reverse(res);

        return res;
    }
};