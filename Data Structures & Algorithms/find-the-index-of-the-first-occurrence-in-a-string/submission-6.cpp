class Solution {
public:
    int strStr(string haystack, string needle) {
        const int base1 = 31;
        const int prime1 = 10e9 + 7;
        const int base2 = 37;
        const int prime2 = 10e9 + 9;

        int power1 = 1;
        int power2 = 1;

        const int m = needle.size();
        const int n = haystack.size();

        for (int i = 0; i < m; ++i) {
            power1 = (power1 * base1) % prime1;
            power2 = (power2 * base2) % prime2;
        }

        int hash1haystack = 0;
        int hash2haystack = 0;
        int hash1needle = 0;
        int hash2needle = 0;
        for (int i = 0; i < m; ++i) {
            hash1needle = (hash1needle * base1 +
                (needle[i] - 'a')) % prime1;
            hash2needle = (hash2needle * base2 +
                (needle[i] - 'a')) % prime2;
            hash1haystack = (hash1haystack * base1 +
                (haystack[i] - 'a')) % prime1;
            hash2haystack = (hash2haystack * base2 +
                (haystack[i] - 'a')) % prime2;
        }

        for (int i = 0; i <= n - m; ++i) {
            if (hash1needle == hash1haystack &&
                hash2needle == hash2haystack) return i;

            hash1haystack = (hash1haystack * base1 -
                power1 * (haystack[i] - 'a') +
                    (haystack[i + m] - 'a') + prime1) % prime1;
            hash2haystack = (hash2haystack * base2 -
                power2 * (haystack[i] - 'a') +
                    (haystack[i + m] - 'a') + prime2) % prime2;
        }

        return -1;
    }
};