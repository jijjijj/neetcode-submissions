class Solution {
public:
    string addBinary(string a, string b) {
        if (a.size() < b.size()) std::swap(a, b);

        const int len = b.size();

        std::string res;
        res.resize(a.size());

        bool carry = 0;
        for (int i = 0; i < a.size(); ++i) {
            const bool v1 = a[a.size() - i - 1] - '0';
            const bool v2 = i < len ? (b[b.size() - i - 1] - '0') : 0;

            // std::cout << v1 << " " << v2 << " " << carry << " " << ((carry ^ v1 ^ v2)) << std::endl;

            res[res.size() - i - 1] = (carry ^ v1 ^ v2) + '0';
            carry = (v1 && v2) || (v1 && carry) || (v2 && carry);
        }

        // 10010
        //   111
        if (carry) res = "1" + res;
        
        return res;
    }
};