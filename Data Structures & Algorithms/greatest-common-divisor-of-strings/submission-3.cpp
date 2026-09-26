class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int size1 = str1.size();
        int size2 = str2.size();

        if (size1 < size2) {
            std::swap(size1, size2);
            std::swap(str1, str2);
        }

        const int g = mygcd(size1, size2);

        for (int i = 0; i < size1; ++i) {
            if (str1[i] != str2[i % g]) return "";
        }

        for (int j = 0; j < size2; ++j) {
            if (str2[j] != str2[j % g]) return "";
        }

        return str1.substr(0, g);
    }

private:
    int mygcd(int a, int b) {
        while (a && b) {
            int tmp = b;
            b = a % b;
            a = tmp;
        }

        return a;
    }
};