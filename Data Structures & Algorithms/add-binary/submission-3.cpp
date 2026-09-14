class Solution {
public:
    string addBinary(string a, string b) {
        const int mx = std::max(a.size(), b.size());

        
        std::string res;
        res.resize(mx);

        bool carry = 0;
        for (int i = 0; i < mx; ++i) {
            const bool v1 = i < a.size() ? a[i] - '0' : 0;
            const bool v2 = i < b.size() ? b[i] - '0' : 0;

            res[i] = (carry ^ v1 ^ v2) + '0';
            carry = (v1 && v2) || (v1 && carry) || (v2 && carry);
        }

        // 10010
        //   111
        if (carry) res += '1';
        
        std::ranges::reverse(res);

        return res;
    }
};