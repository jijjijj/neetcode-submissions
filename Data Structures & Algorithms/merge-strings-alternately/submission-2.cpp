class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        const int size1 = word1.size();
        const int size2 = word2.size();

        std::string res;
        res.reserve(size1 + size2);
        
        int i = 0;
        int j = 0;

        while (i < size1 || j < size2) {
            if (i < size1) res += word1[i++];
            if (j < size2) res += word2[j++];
        }

        return res;
    }
};