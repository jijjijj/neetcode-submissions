class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int size1 = str1.size();
        int size2 = str2.size();

        for (int l = std::min(size1, size2); l > 0; --l) {
            if ((size1 % l) || (size2 % l)) continue;
            
            bool valid = true;
            for (int i = 0; i < size1; ++i) {
                if (str1[i] != str2[i % l]) {
                    valid = false;
                    break;
                }
            }
            if (!valid) continue;
            for (int j = 0; j < size2; ++j) {
                if (str2[j] != str2[j % l]) {
                    valid = false;
                    break;
                }
            }

            if (valid) return str2.substr(0, l);
        }

        return "";
    }
};