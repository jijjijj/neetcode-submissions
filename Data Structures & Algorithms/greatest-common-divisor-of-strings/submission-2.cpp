class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        while (str1.size() && str2.size()) {
            int s1 = str1.size();
            int s2 = str2.size();

            if (s1 < s2) {
                std::swap(s1, s2);
                std::swap(str1, str2);
            }

            int i = 0;

            for (int j = 0; j < s1; ++j) {
                if (str1[s1 - j - 1] == str2[s2 - (j % s2) - 1]) {
                    ++i;
                } else break;
            }

            i /= s2;
            i *= s2;

            if (!i) return "";

            str1 = str1.substr(0, s1 - i);
            std::swap(str1, str2);
        }

        return str1.empty() ? str2 : str1;
    }
};