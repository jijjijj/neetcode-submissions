class Solution {
public:
    bool wordPattern(string pattern, string s) {
        std::unordered_map<char, std::string> mp1;
        std::unordered_map<std::string, char> mp2;

        std::stringstream ss;
        ss << s;

        std::string word;
        for (int i = 0; i < pattern.size(); ++i) {
            const char c = pattern[i];
            std::getline(ss, word, ' ');

            if ((mp1.contains(c) && mp1[c] != word) ||
                (mp2.contains(word) && mp2[word] != c)) return false;

            mp1[c] = word;
            mp2[word] = c;
        }

        return true;
    }
};