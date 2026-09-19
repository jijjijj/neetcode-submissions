class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        const int size1 = word1.size();
        const int size2 = word2.size();

        std::string res;
        res.reserve(size1 + size2);
        
        int i = 0;

        while (i < size1 || i < size2) {
            if (i < size1) res += word1[i];
            if (i < size2) res += word2[i];
            ++i;
        }

        return res;
    }
};