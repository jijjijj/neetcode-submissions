class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        const int size1 = word1.size();
        const int size2 = word2.size();

        std::string res(size1 + size2, ' ');
        int at = 0;
        int i1 = 0;
        int i2 = 0;
        for (int i = 0; i < std::min(size1, size2) * 2; ++i) {
            res[at++] = ((i & 1) ? word2[i2++] : word1[i1++]);
        }

        for (; i1 < size1; ++i1) res[at++] = word1[i1];
        for (; i2 < size2; ++i2) res[at++] = word2[i2];

        return res;
    }
};